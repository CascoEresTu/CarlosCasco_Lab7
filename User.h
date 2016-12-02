#pragma once
#include <string>
#include <iostream>
#include <sstream>

using std::string;

class User {
protected:
    string name;
    string email;
    string password;
public:
    User();
    User(string,string,string);
    virtual ~User();
    void setName(string);
    string getName();
    void setEmail(string);
    string getEmail();
    void setPassword(string);
    string getPassword();

};
