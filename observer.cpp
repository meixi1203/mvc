#include "observer.h"
#include <algorithm>

Observer::Observer()
{
}

Observer::~Observer()
{
}

bool Observer::RegisterMsg(MessageType tpye)
{
    m_MsgType.push_back(tpye);
    return !m_MsgType.empty();
}

bool Observer::find(MessageType tpye)
{
    bool ret = false;
    std::list<MessageType>::iterator iter = std::find(m_MsgType.begin(), m_MsgType.end(), tpye);

    if(iter != m_MsgType.end())
    {
        ret = true;
    }
    return ret;
}