#ifndef __OBSERVER_H
#define __OBSERVER_H

#include "common.h"
#include <list>

class Observer
{
    public:
        Observer();
        virtual ~Observer();
        virtual void update(MessageType tpye) = 0;
        bool RegisterMsg(MessageType tpye);
        bool find(MessageType tpye);

    private:
        std::list<MessageType> m_MsgType;
};

#endif