#ifndef SIDEWIDGET_H
#define SIDEWIDGET_H
#include "CorePlugin_global.h"
#include "widgetfactory.h"
#include "uniqueidmanager.h"
#include "sidepage.h"
#include <QtCore>
#include "menubar.h"

namespace Ui {

class SideWidget;
}

namespace CorePlugin {

class COREPLUGINSHARED_EXPORT SideWidget : public Widget {
    Q_OBJECT
public:
    explicit SideWidget(const ID& id);
    ~SideWidget();
    void addSidePage(SidePage* page);
    void gotoPage(int index);
    int getCurrentIndex() const;
    void compactHeader();
signals:

public slots:
private:
    void removePageByIndex(int index);
    QVector<SidePage*> m_pageList;
    int m_currentIndex;
    MenuBar* m_menubar;
    Ui::SideWidget* ui;
private slots:
    void changeIndex();
};
}

#endif // SIDEWIDGET_H
