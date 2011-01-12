#include "imessage.h"

Message::MsgType Message::IMessage::getType() const
{
    return this->m_ror_type;
}
