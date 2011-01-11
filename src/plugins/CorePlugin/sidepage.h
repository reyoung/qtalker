#ifndef SIDEPAGE_H
#define SIDEPAGE_H
#include "widgetfactory.h"

#include <CorePlugin_global.h>
#include <QObject>

namespace CorePlugin {

class COREPLUGINSHARED_EXPORT SidePage : public Widget {
public:
    SidePage(const ID& id);
    virtual CommandLinkButton* getHeader() = 0;
    virtual QWidget* getWidget() = 0;
    virtual QString getTitle() = 0;
};
}

#endif // SIDEPAGE_H
