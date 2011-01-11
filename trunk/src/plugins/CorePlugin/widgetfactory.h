#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H
#include "CorePlugin_global.h"
#include "idable.h"
#include <QtGui>
#include <QtCore>

namespace CorePlugin {

class COREPLUGINSHARED_EXPORT Widget: public QWidget, public IDAble {

    friend class WidgetFactory;
protected:
    Widget(const ID& id, QWidget* parent = 0) : QWidget(parent), IDAble(id) {}
};

class COREPLUGINSHARED_EXPORT PushButton: public QPushButton, public IDAble {

    friend class WidgetFactory;
protected:
    PushButton(const ID& id, QWidget* parent = 0) : QPushButton(parent), IDAble(id) {}
};

class COREPLUGINSHARED_EXPORT ComboBox: public QComboBox, public IDAble {

    friend class WidgetFactory;
protected:
    ComboBox(const ID& id, QWidget* parent = 0) : QComboBox(parent), IDAble(id) {}
};

class COREPLUGINSHARED_EXPORT LineEdit: public QLineEdit, public IDAble {

    friend class WidgetFactory;
protected:
    LineEdit(const ID& id, QWidget* parent = 0) : QLineEdit(parent), IDAble(id) {}
};

class COREPLUGINSHARED_EXPORT CommandLinkButton: public QCommandLinkButton, public
            IDAble {

    friend class WidgetFactory;
private:
    CommandLinkButton(const ID& id, QWidget* parent = 0) : QCommandLinkButton(parent), IDAble(id) {
        this->setMaximumWidth(40);
    }
};
class COREPLUGINSHARED_EXPORT SystemTrayIcon:public QSystemTrayIcon,public IDAble
{
        friend class WidgetFactory;
private:
SystemTrayIcon(const ID& id,QObject* parent = 0):QSystemTrayIcon(parent),IDAble(id){}
};


class MainForm;

class MenuBar;

class SideWidget;
//enum MenuBar::Style;

#define DEFINE_WIDGET_FACTORY_DATA(Class) QHash<int,Class*> m_##Class##_List;


class COREPLUGINSHARED_EXPORT WidgetFactory {
private:
    WidgetFactory();
public:
    static void init();
    static WidgetFactory* instance();
    ~WidgetFactory();
    Widget* createWidget(const ID& id);
    Widget* getWidget(const ID& id);
    PushButton* createPushButton(const ID& id);
    PushButton* getPushButton(const ID& id);
    ComboBox* createComboBox(const ID& id);
    ComboBox* getComboBox(const ID& id);
    LineEdit* createLineEdit(const ID& id);
    LineEdit* getLineEdit(const ID& id);
    MainForm* getMainForm();
    CommandLinkButton* createCommandLinkButton(const ID& id);
    CommandLinkButton* getCommandLinkButton(const ID& id);
    MenuBar* createMenuBar(const ID& id, int st);
    MenuBar* getMenuBar(const ID& id);
    MenuBar* getBottomMenuBar();

    SideWidget* getMainSideWidget();
    SideWidget* createSideWidget(const ID& id);
    SideWidget* getSideWidget(const ID& id);

    SystemTrayIcon* getSystemTrayIcon();

private:
    static WidgetFactory* m_instance;
    QHash <int, Widget*> m_widList;
    QHash <int, MenuBar* > m_menuBar;

    DEFINE_WIDGET_FACTORY_DATA(PushButton)
    DEFINE_WIDGET_FACTORY_DATA(ComboBox)
    DEFINE_WIDGET_FACTORY_DATA(LineEdit)
    DEFINE_WIDGET_FACTORY_DATA(CommandLinkButton)
    DEFINE_WIDGET_FACTORY_DATA(SideWidget)
    static SystemTrayIcon* m_trayIcon;
    static MenuBar* m_bottomMenuBar;
    static MainForm* m_staticMainForm;
    static SideWidget* m_mainSideWidget;
    template <class T>
    static void cleanHashList(QHash<int, T* >* list);
};
}

#endif // WIDGETFACTORY_H
