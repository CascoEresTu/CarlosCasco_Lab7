#include "Supervisor.h"

/*
Supervisor();
Supervisor(string,string,string,int);
~Supervisor();
void setEntradas(int);
int getEntradas();

*/

 Supervisor::Supervisor(){

 }

 Supervisor::Supervisor(string nombre ,string correo ,string contra , int entries): User(nombre , correo , contra){
     this->entrada = entries;
 }

Supervisor::~Supervisor(){
    std::cout << "adios supervisor" << std::endl;

}

void Supervisor::setEntradas(int entries){
    this->entrada = entries;
}


int Supervisor::getEntradas(){
    return this->entrada;
}
