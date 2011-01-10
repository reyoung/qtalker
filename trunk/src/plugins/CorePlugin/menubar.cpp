#include "menubar.h"

using namespace CorePlugin;
MenuBar::MenuBar(const ID& id, Style st) :
        Widget(id) {
    if (st == Vertical) {
        this->m_layout = new QVBoxLayout(this);
    }

    else {
        this->m_layout = new QHBoxLayout(this);
    }

    this->setLayout(m_layout);

    this->setContentsMargins(0, 0, 0, 0);
}

//void CorePlugin::MenuBar::addButton(CorePlugin::CommandLinkButton *button)
//{
//    this->m_layout->addWidget(button);
//}

void CorePlugin::MenuBar::addWidget(QWidget *w, QWidget *before) {
    if (before) {
        int index = this->m_layout->indexOf(before);

        if (index == -1) {
            qWarning() << "Before Widget Not Exist";
        }

        else {
            this->m_layout->insertWidget(index, w);
        }
    }

    else {
        this->m_layout->addWidget(w);
    }
}

void CorePlugin::MenuBar::addSpacer(int index) {
    if (index == -1)
        index = this->m_layout->count();

    if (this->m_layout->metaObject()->className() == "QVBoxLayout") {
        this->m_layout->insertSpacerItem(index, new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));
    }

    else {
        this->m_layout->insertSpacerItem(index, new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    }
}
