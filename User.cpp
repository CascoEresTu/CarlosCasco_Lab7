#include "User.h"

/*
User();
User(string,string,string);
~User();
void setName(string);
string getName();
void setEmail(string);
string getEmail();
void setPassword(string);
string getPassword();*/

User::User(){
    this->name = "";
    this->email = "";
    this->password = "";
}

User::User(string nombre, string correo, string contra){
    this->name = nombre;
    this->email = correo;
    this->password = contra;
}

User::~User(){
    std::cout << "adios usuario" << std::endl;
}

void User::setName(string nombre){
    this->name= nombre;
}

string User::getName(){
    return this->name;
}


void User::setEmail(string correo){
    this->email= correo;
}

string User::getEmail(){
    return this->email;
}


void User::setPassword(string contra){
    this->password= contra;
}

string User::getPassword(){
    return this->password;
}
