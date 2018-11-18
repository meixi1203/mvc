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
    m_msgType.push_back(tpye);
    return !m_msgType.empty();
}

bool Observer::find(MessageType tpye)
{
    bool ret = false;
    std::list<MessageType>::iterator iter = std::find(m_msgType.begin(), m_msgType.end(), tpye);

    if(iter != m_msgType.end())
    {
        ret = true;
    }
    return ret;
}