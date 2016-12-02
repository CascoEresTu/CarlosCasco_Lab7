#pragma once
#include "User.h"

class Supervisor : public User{

private:
    int entrada;
public:
     Supervisor();
     Supervisor(string,string,string,int);
     ~Supervisor();
     void setEntradas(int);
     int getEntradas();
};
