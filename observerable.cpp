#include "observerable.h"
#include <algorithm>
#include <unistd.h>

ObserverAble::ObserverAble():m_running(true), m_thread(std::bind(&ObserverAble::ThreadHandler, this))
{
    m_observerList.clear();
}

ObserverAble::~ObserverAble()
{
    m_observerList.clear();

    if(m_running)
    {
        m_running = false;
        m_thread.join();
    } 
}

ObserverAble* ObserverAble::GetObserverAbleInstabce()
{
    static ObserverAble* observerable = new ObserverAble();

    if(observerable)
    {
        return observerable;
    }
    return NULL;

}

bool ObserverAble::RegisterObserver(Observer *observer)
{
    m_observerList.push_back(observer);
    return !m_observerList.empty();
}

bool ObserverAble::SendEvent(MessageType msgType)
{
    std::lock_guard<std::mutex> guard(m_mutex);
    m_tasks.push_front(std::bind(&ObserverAble::detach, this, msgType));
    return true;
}

void ObserverAble::ThreadHandler()
{
    Task task = NULL;

    while(m_running)
    {
        {
            std::lock_guard<std::mutex> guard(m_mutex);
            if(m_tasks.empty())
            {
                usleep(10);
            }
            if(!m_tasks.empty())
            {
                task = m_tasks.back();  //从任务队列中获取最开始任务
                m_tasks.pop_back();     //将取走的任务弹出任务队列
                task(); //执行任务
            }
        }
    }
}

bool ObserverAble::PostRunable(Task task)
{
    std::lock_guard<std::mutex> guard(m_mutex);
    m_tasks.push_front(task);
    return true;
}

void ObserverAble::detach(MessageType msgType)
{
    for(std::list<Observer*>::iterator iter = m_observerList.begin(); iter != m_observerList.end(); iter++)
    {
        if((*iter)->find(msgType))
        {
            (*iter)->update(msgType);
        }
    }
}