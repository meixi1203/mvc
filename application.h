#ifndef __APPLICATION_H
#define __APPLICATION_H

class Model;
class View;
class Controller;

class Application 
{
    public:
        Application();
        ~Application();

        bool run();

    private:
        Model *m_model;
        View *m_view;
        Controller * m_controller;
};

#endif