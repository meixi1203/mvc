#include "model.h"
#include "observerable.h"

Model::Model():m_data(-1)
{

}

Model::~Model()
{

}

bool Model::SetA(int data)
{
    m_data = data;
    ObserverAble::GetObserverAbleInstabce()->SendEvent(MessageType_A);
    ObserverAble::GetObserverAbleInstabce()->SendEvent(MessageType_B);
    ObserverAble::GetObserverAbleInstabce()->SendEvent(MessageType_C);
    
    //for test PostRunable IF
    ObserverAble::GetObserverAbleInstabce()->PostRunable([]() { std::cout << "[Model::SetA] hello world!" << std::endl;});

    return true;

}

int Model::GetA()
{
    return m_data;
}
