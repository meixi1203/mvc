#ifndef __CONTROLLER_H
#define __CONTROLLER_H

class Model;
class Controller
{
    public:
        Controller();
        ~Controller();

        void MessageHander();
        bool SetModel(Model *model);
        bool SetA(int data);

    private:
        Model *m_model;
};

#endif