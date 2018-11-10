#include "view.h"
#include "observerable.h"

View::View()
{
    this->RegisterMsg(MessageType_A);
    this->RegisterMsg(MessageType_B);

    ObserverAble::GetObserverAbleInstabce()->RegisterObserver(this);
}

View::~View()
{

}

void View::update(MessageType tpye)
{
    std::cout << "[View::update]  MessageType = " << tpye << std::endl;
}
