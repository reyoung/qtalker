#ifndef MAINFORM_H
#define MAINFORM_H
#include "widgetfactory.h"
#include "CorePlugin_global.h"

namespace Ui {

class MainForm;
}

namespace CorePlugin {

class COREPLUGINSHARED_EXPORT MainForm : public Widget {
    Q_OBJECT
public:
    explicit MainForm();
    ~MainForm();
    void addWidgetToHeader1(QWidget* w);
    void addWidgetToHeader2(QWidget* w);
    void addWidgetToBody(QWidget* w);
    void addWidgetToBottom1(QWidget* w);
    void addWidgetToBottom2(QWidget* w);

    void removeWidgetFromHeader1(QWidget* w);
    void removeWidgetFromHeader2(QWidget* w);
    void removeWidgetFromBody(QWidget* w);
    void removeWidgetFromBottom1(QWidget* w);
    void removeWidgetFromBottom2(QWidget* w);
signals:

public slots:
private:
    Ui::MainForm* ui;
};
}

#endif // MAINFORM_H
