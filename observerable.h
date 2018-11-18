#ifndef __OBSERVERABLE_H
#define __OBSERVERABLE_H

#include "observer.h"
#include "common.h"
#include <list>
#include <atomic>
#include <mutex>
#include <thread>
#include <functional>

class ObserverAble
{
    public:
        typedef std::function<void(void)> Task;
        static ObserverAble* GetObserverAbleInstabce();
        bool RegisterObserver(Observer *observer);
        bool SendEvent(MessageType msgType);
        void ThreadHandler();
        bool PostRunable(Task task);

    private:
        void detach(MessageType msgType);
        ObserverAble();
        ~ObserverAble();

    private:
        std::list<Observer*> m_observerList;
        std::list<Task> m_tasks;
        std::mutex m_mutex;
        std::atomic<bool> m_running;
        std::thread m_thread;
};

#endif