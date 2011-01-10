#include "mainform.h"
#include "coreconst.h"
#include "ui_mainform.h"
using namespace CorePlugin;
MainForm::MainForm() :
        Widget(Const::MainForm),ui(new Ui::MainForm) {
    ui->setupUi(this);
}
MainForm::~MainForm() {
    delete ui;
}
void MainForm::addWidgetToBody(QWidget *w) {
    this->ui->bodyLayout->addWidget(w);
}
void MainForm::addWidgetToBottom1(QWidget *w) {
    this->ui->bottomLayout->addWidget(w);
}
void MainForm::addWidgetToHeader1(QWidget *w) {
    this->ui->headerLayout->addWidget(w);
}
void MainForm::addWidgetToBottom2(QWidget *w) {
    this->ui->bottomLayout->addWidget(w);
}
void MainForm::addWidgetToHeader2(QWidget *w) {
    this->ui->bottom2Layout->addWidget(w);
}
void MainForm::removeWidgetFromBody(QWidget *w) {
    this->ui->bodyLayout->removeWidget(w);
}
void MainForm::removeWidgetFromBottom1(QWidget *w) {
    this->ui->bottomLayout->removeWidget(w);
}
void MainForm::removeWidgetFromBottom2(QWidget *w) {
    this->ui->bottom2Layout->removeWidget(w);
}
void MainForm::removeWidgetFromHeader1(QWidget *w) {
    this->ui->headerLayout->removeWidget(w);
}
void MainForm::removeWidgetFromHeader2(QWidget *w) {
    this->ui->header2Layout->removeWidget(w);
}
