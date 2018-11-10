#include "application.h"
#include "model.h"
#include "view.h"
#include "controller.h"


Application::Application():m_model(nullptr),m_view(nullptr),m_controller(nullptr)
{
    m_model = new Model();
    m_view = new View();
    m_controller = new Controller();

    if(m_model)
    {
        if(m_controller)
        {
            m_controller->SetModel(m_model);
        }
        else
        {
            std::cout << "[Application::Application] m_controller is NULL" << std::endl;
        }
    }
    else
    {
        std::cout << "[Application::Application] m_model is NULL" << std::endl;
    }
}

Application::~Application()
{
    delete m_model;
    m_model = nullptr;

    delete m_view;
    m_view = nullptr;

    delete m_controller;
    m_controller = nullptr;

}

bool Application::run()
{
    bool ret = false;

    if(m_controller)
    {
        m_controller->MessageHander();
        ret = true;
    }
     return ret;
}