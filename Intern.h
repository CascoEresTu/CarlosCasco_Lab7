#pragma once

#include "User.h"
#include <string>
using std::string;

class Intern : public User{
private:
    int daysworked;
public:
     Intern();
     Intern(string,string,string,int);
     ~Intern();
     void setDaysWorked(int);
     int getDaysWorked();
};
