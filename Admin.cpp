#include "Admin.h"

/*
Admin();
Admin(string,string,string,string);
~Admin();
void setDate(string);
string getDate();
*/

Admin::Admin(){

}

Admin::Admin(string nombre ,string correo ,string contra , string fecha): User(nombre , correo , contra){
    this->date = fecha;
}

Admin::~Admin(){
    std::cout << "adios admin" << std::endl;

}

void Admin::setDate(string fecha){
    this->date = fecha;
}

string Admin::getDate(){
    return this->date;
}
