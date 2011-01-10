#include "widgetfactory.h"
#include "mainform.h"
using namespace CorePlugin;
#define ImplementWidgetFactory(Class) \
Class* WidgetFactory::create##Class (const ID &id)\
{\
    Class* mid = new Class(id);\
    if(mid->isIdValid())\
    {\
     this->m_##Class##_List.insert(mid->getIdNumber(),mid);\
     return mid;\
    }\
    else\
    {\
        delete mid;\
        return 0;\
    }\
}\
Class* WidgetFactory::get##Class (const ID &id)\
{\
    uint hash = UniqueIDManager::instance()->getUID(id);\
    return this->m_##Class##_List.value(hash,0);\
}

#define CleanHashList(Class) this->cleanHashList(&this->m_##Class##_List)

ImplementWidgetFactory(PushButton)
ImplementWidgetFactory(ComboBox)
ImplementWidgetFactory(LineEdit)


WidgetFactory* WidgetFactory::m_instance = 0;
MainForm* WidgetFactory::m_staticMainForm = 0;
WidgetFactory::~WidgetFactory() {
}

WidgetFactory::WidgetFactory() {
}
void WidgetFactory::init() {
    static WidgetFactory ins;
    static MainForm mf;
    m_instance = &ins;
    m_staticMainForm = &mf;
}
WidgetFactory* WidgetFactory::instance() {
    return m_instance;
}
Widget* WidgetFactory::createWidget(const ID &id) {
    Widget* wid = new Widget(id);
    if (wid->isIdValid()) {
        this->m_widList.insert(wid->getIdNumber(),wid);
        return wid;
    } else {
        delete wid;
        return 0;
    }
}
Widget* WidgetFactory::getWidget(const ID &id) {
    uint hash = UniqueIDManager::instance()->getUID(id);
    return this->m_widList.value(hash,0);
}
MainForm* WidgetFactory::getMainForm() {
    return this->m_staticMainForm;
}

template <class T>
void WidgetFactory::cleanHashList(QHash<int, T *> *list) {
    QVector<T *> hlist = list->values().toVector();
    for (int i=0;i<hlist.size();++i) {
        delete hlist[i];
    }
}
