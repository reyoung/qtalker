#ifndef MENUBAR_H
#define MENUBAR_H
#include "CorePlugin_global.h"

#include "uniqueidmanager.h"
#include <QtGui>
#include "widgetfactory.h"

namespace CorePlugin {

class Widget;

class COREPLUGINSHARED_EXPORT MenuBar : public Widget {

public:
    enum Style {
        Vertical,
        Horizontal
    };
    explicit MenuBar(const ID& id, Style st);
    void addWidget(QWidget* w, QWidget* before = 0);
    void addSpacer(int index = -1);
private:
    QBoxLayout* m_layout;
};
}

#endif // MENUBAR_H
