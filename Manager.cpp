#include "Manager.h"

Manager::Manager(){

}

Manager::Manager(string nombre ,string correo ,string contra , double sueldo): User(nombre , correo , contra){
    this->salary = sueldo;
}

Manager::~Manager(){

}

void Manager::setSalary(double sueldo){
    this->salary = sueldo;
}

double Manager::getSalary(){
    return this->salary;
}
