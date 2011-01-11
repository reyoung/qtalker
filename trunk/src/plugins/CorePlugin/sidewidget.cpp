#include "sidewidget.h"
#include "ui_SideWidget.h"

using namespace CorePlugin;
CorePlugin::SideWidget::SideWidget(const CorePlugin::ID &id) : Widget(id), ui(new Ui::SideWidget) {

    ui->setupUi(this);
    QString m_id = id;
    m_id.append(".Menubar");
    ID mbid(m_id.toStdString().c_str());
    this->m_menubar = WidgetFactory::instance()->createMenuBar(mbid, (int) MenuBar::Vertical);

//    this->m_menubar->show();;
    this->m_menubar->setParent(this);
    this->ui->headerLayout->addWidget(m_menubar);
//    qDebug()<<"OK?"<<m_menubar;
    this->setContentsMargins(0, 0, 0, 0);

}

SideWidget::~SideWidget() {
    delete this->ui;
}

void CorePlugin::SideWidget::addSidePage(CorePlugin::SidePage *page) {
    this->m_pageList.append(page);
    this->m_menubar->addWidget(page->getHeader());
    this->connect(page->getHeader(), SIGNAL(clicked()), this, SLOT(changeIndex()));
}

void CorePlugin::SideWidget::gotoPage(int index) {
    if (index<0 && index >= this->m_pageList.size()) {
        return;
    }

    else {
        QWidget* w = this->m_pageList[index]->getWidget();

        this->removePageByIndex(this->m_currentIndex);
        this->m_pageList[index]->getHeader()->setCheckable(true);
        this->m_pageList[index]->getHeader()->setChecked(true);
        ui->titleLabel->setText(m_pageList[index]->getTitle());
        this->ui->pageLayout->addWidget(w);
        this->m_currentIndex = index;
    }
}

void CorePlugin::SideWidget::removePageByIndex(int index) {
    if (index<0 && index >= this->m_pageList.size()) {
        return;
    }

    else {
        QWidget* w = this->m_pageList[index]->getWidget();
        this->m_pageList[index]->getHeader()->setCheckable(false);
        this->m_pageList[index]->getHeader()->setChecked(false);
        this->ui->pageLayout->removeWidget(w);
    }
}

int CorePlugin::SideWidget::getCurrentIndex() const {
    return this->m_currentIndex;
}

void CorePlugin::SideWidget::changeIndex() {
    int i;

    for (i = 0;i < this->m_pageList.size();++i) {
        if (m_pageList[i]->getHeader() == sender()) {
            break;
        }
    }

    this->gotoPage(i);
}

void CorePlugin::SideWidget::compactHeader() {
    this->m_menubar->addSpacer();
}

