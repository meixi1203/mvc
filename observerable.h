#ifndef __OBSERVERABLE_H
#define __OBSERVERABLE_H

#include "observer.h"
#include "common.h"
#include <list>
#include <mutex>
#include <thread>
#include <functional>

class ObserverAble
{
    public:
        static ObserverAble* GetObserverAbleInstabce();
        bool RegisterObserver(Observer *observer);
        bool SendEvent(MessageType msgType);
        void ThreadHandler();

    private:
        void detach(MessageType msgType);
        ObserverAble();
        ~ObserverAble();
        typedef std::function<void(void)> Task;

    private:
        std::list<Observer*> m_ObserverList;
        std::list<Task> m_tasks;
        std::mutex m_mutex;
        bool m_running;
        std::thread m_thread;
};

#endif