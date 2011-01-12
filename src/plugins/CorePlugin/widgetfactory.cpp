#include "widgetfactory.h"
#include "mainform.h"
#include "menubar.h"
#include "sidewidget.h"
#include "coreconst.h"

using namespace CorePlugin;
#define ImplementWidgetFactory(Class) \
Class* WidgetFactory::create##Class (const ID &id) \
{\
    Class* mid = new Class ( id );\
    \
\
    if ( mid->isIdValid() )\
    {\
       this->m_##Class##_List.insert ( mid->getIdNumber(), mid );\
       return mid;\
    }\
    else\
    {\
        delete mid;\
        qDebug() << QObject::tr ( "%1 Error" ).arg ( mid->getID() );\
        return 0;\
    }\
}\
Class* WidgetFactory::get##Class ( const ID &id ) \
{\
    uint hash = UniqueIDManager::instance()->getUID ( id );\
    return this->m_##Class##_List.value ( hash, 0 );\
}

#define CleanHashList (Class) this->cleanHashList(&this->m_##Class##_List)

ImplementWidgetFactory(PushButton)
ImplementWidgetFactory(ComboBox)
ImplementWidgetFactory(LineEdit)
ImplementWidgetFactory(CommandLinkButton)
ImplementWidgetFactory(SideWidget)


WidgetFactory* WidgetFactory::m_instance = 0;
MainForm* WidgetFactory::m_staticMainForm = 0;
SideWidget* WidgetFactory::m_mainSideWidget = 0;
MenuBar* WidgetFactory::m_bottomMenuBar = 0;
SystemTrayIcon* WidgetFactory::m_trayIcon = 0;

WidgetFactory::~WidgetFactory() {
}

WidgetFactory::WidgetFactory() {

}

void WidgetFactory::init() {
    static WidgetFactory ins;
    static MainForm mf;
    m_instance = &ins;
    m_staticMainForm = &mf;
    static SideWidget sw(Const::MainSideWidget);
    Q_ASSERT(sw.isIdValid());
    m_mainSideWidget = &sw;
    static MenuBar * mb= ins.createMenuBar(Const::MainBottomMenuBar,MenuBar::Horizontal);
    m_trayIcon = new SystemTrayIcon(Const::TrayIcon,&mf);
    m_trayIcon->setIcon(QIcon(":/icon/trayicon.ico"));
    QObject::connect(QApplication::instance(),SIGNAL(aboutToQuit()),m_trayIcon,SLOT(deleteLater()));

    m_bottomMenuBar = mb;
    mb->setMaximumHeight(40);
    m_staticMainForm->addWidgetToBottom1(mb);
    m_staticMainForm->addWidgetToBody(m_mainSideWidget);


}

WidgetFactory* WidgetFactory::instance() {
    return m_instance;
}

Widget* WidgetFactory::createWidget(const ID &id) {
    Widget* wid = new Widget(id);

    if (wid->isIdValid()) {
        this->m_widList.insert(wid->getIdNumber(), wid);
        return wid;
    }

    else {
        delete wid;
        return 0;
    }
}

Widget* WidgetFactory::getWidget(const ID &id) {
    uint hash = UniqueIDManager::instance()->getUID(id);
    return this->m_widList.value(hash, 0);
}

MainForm* WidgetFactory::getMainForm() {
    return this->m_staticMainForm;
}

template <class T>
void WidgetFactory::cleanHashList(QHash<int, T *> *list) {
    QVector<T *> hlist = list->values().toVector();

    for (int i = 0;i < hlist.size();++i) {
        delete hlist[i];
    }
}

CorePlugin::MenuBar * CorePlugin::WidgetFactory::createMenuBar(const CorePlugin::ID &id, int st) {
    MenuBar* mid = new MenuBar(id, (MenuBar::Style) st);

    if (mid->isIdValid()) {
        this->m_menuBar.insert(mid->getIdNumber(), mid);
        return mid;
    }

    else {

        delete mid;
        return 0;
    }
}

CorePlugin::MenuBar * CorePlugin::WidgetFactory::getMenuBar(const CorePlugin::ID &id) {
    uint hash = UniqueIDManager::instance()->getUID(id);
    return this->m_menuBar.value(hash, 0);
}

CorePlugin::SideWidget * CorePlugin::WidgetFactory::getMainSideWidget() {
    return m_mainSideWidget;
}

CorePlugin::MenuBar * CorePlugin::WidgetFactory::getBottomMenuBar()
{
    return m_bottomMenuBar;
}

CorePlugin::SystemTrayIcon * CorePlugin::WidgetFactory::getSystemTrayIcon()
{
    return m_trayIcon;
}

