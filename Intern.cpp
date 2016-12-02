#include "Intern.h"

Intern::Intern(){

}

Intern::Intern(string nombre ,string correo ,string contra , int dias): User(nombre , correo , contra){
    this->daysworked = dias;
}

Intern::~Intern(){
    std::cout << "adios interno" << std::endl;

}

void Intern::setDaysWorked(int dias){
    this->daysworked = dias;
}

int Intern::getDaysWorked(){
    return this->daysworked;
}
