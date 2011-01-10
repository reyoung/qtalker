#include "action.h"

using namespace CorePlugin;
Action::Action(const ID& id, QWidget *parent) :
        QAction(parent), m_id(id) {
}
