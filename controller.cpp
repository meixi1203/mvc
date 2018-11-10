#include "controller.h"
#include "model.h"
#include <unistd.h>
#include <iostream>

Controller::Controller():m_model(nullptr)
{

}

Controller::~Controller()
{
    m_model = nullptr;
}

void Controller::MessageHander()
{
    int data = 100;
    while(1)
    {
        this->SetA(data);
        sleep(1);
    }
}

bool Controller::SetModel(Model *model)
{
    m_model = model;
    return true;
}

bool Controller::SetA(int data)
{
    bool ret = false;

    if(m_model)
    {
        ret = m_model->SetA(data);
    }
    else
    {
        std::cout << "[Controller::SetA] m_model is NULL " << std::endl;
    }
    return ret;
}