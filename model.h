#ifndef __MODEL_H
#define __MODEL_H

class Model
{
    public:
        Model();
        ~Model();

        bool SetA(int data);
        int GetA();

    private:
        int m_data;
};

#endif