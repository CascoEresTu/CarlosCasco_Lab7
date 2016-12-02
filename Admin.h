#pragma once

#include "User.h"

class Admin : public User {
private:
    string date;
public:
     Admin();
     Admin(string,string,string,string);
     ~Admin();
     void setDate(string);
     string getDate();
};
