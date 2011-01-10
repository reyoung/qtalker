#ifndef HELLOPAGE_H
#define HELLOPAGE_H
#include <sidepage.h>
#include <widgetfactory.h>

using namespace CorePlugin;

class HelloPage: public SidePage {
public:
    HelloPage() : SidePage("HelloPlugin.Page") {}

    virtual CommandLinkButton* getHeader() {
        static CommandLinkButton* cmdlink = WidgetFactory::instance()->createCommandLinkButton("HelloPlugin.Page.Header");
        cmdlink->setText(tr("Hello world"));
        cmdlink->setIcon(QIcon());
        return cmdlink;
    }

    virtual QWidget* getWidget() {
        static PushButton* pb = WidgetFactory::instance()->createPushButton("HelloWorld.PB");
        return pb;
    }
};

#endif // HELLOPAGE_H
