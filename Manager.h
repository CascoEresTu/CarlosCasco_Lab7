#pragma once
#include "User.h"

class Manager : public User{

private:
    double salary;
public:
     Manager();
     Manager(string,string,string,double);
     ~Manager();
     void setSalary(double);
     double getSalary();
};
