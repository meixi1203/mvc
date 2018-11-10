#ifndef __VIEW_H
#define __VIEW_H

#include "observer.h"
#include "common.h"

class View : public Observer
{
    public:
        View();
        ~View();
        virtual void update(MessageType tpye);
};

#endif
