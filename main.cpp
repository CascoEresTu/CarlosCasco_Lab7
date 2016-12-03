#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cmath>
#include<stdlib.h>

using namespace std;
void ingresar();
void guardarDatos();
void cargarDatos();
void menuAdmin();
void menuSupervisor();
void menuInterno();
void menuManager();

vector<User*> usuarios;
User* logeado;

int main(int argc, char const *argv[]) {
    cargarDatos();

    Admin* a = new Admin("Juan","cgc@asd.com","numerito", "Martes");
    Manager* b = new Manager("Jose","cgc@asd.com","numero", 300.0);
    Intern* c = new Intern("Pedro","cgc@asd.com","number", 1);
    Supervisor* d = new Supervisor("Juan","cgc@asd.com","kakaroto", 1);

    //Estos son majes para que probes todo;
    //PD: si no , se caga esta mierda;
    usuarios.push_back(a);
    usuarios.push_back(b);
    usuarios.push_back(c);
    usuarios.push_back(d);

    //usuarios.push_back(pJuan);
    std::cout << "hola" << std::endl;
    //guardarDatos(usuarios);

    ingresar();
    //std::cout << usuarios.at(1)->getName() << std::endl;
    //guardarDatos(usuarios);

    return 0;
}

void menuManager(){

    int op = 0 ;

    while( op != 5){
        cout<<"   MENU"<<endl;
        cout<<"1. Crear Supervisor"<<endl;
        cout<<"2. Crear Interno"<<endl;
        cout<<"3. Eliminar"<<endl;
        cout<<"4. Listar" << std::endl;
        cout<<"5. Salir"<<endl;

        cout<<"Ingrese una opcion: ";
        cin>> op ;

        string nombre;
        string correo;
        string contra;
        string fechain;


        double salario;
        //int diastrabajados;

        if (op == 1) {
            std::cout << "Ingrese el nombre: " << std::endl;
            cin >> nombre;
            std::cout << "Ingrese el correo: " << std::endl;
            cin >> correo;
            std::cout << "Ingrese la contraseña: " << std::endl;
            cin >> contra;


            usuarios.push_back(new Supervisor(nombre,correo,contra,1) );

        }


        if (op == 2) {
            std::cout << "Ingrese el nombre: " << std::endl;
            cin >> nombre;
            std::cout << "Ingrese el correo: " << std::endl;
            cin >> correo;
            std::cout << "Ingrese la contraseña: " << std::endl;
            cin >> contra;

            usuarios.push_back(new Intern(nombre,correo,contra,1));

        }

        if (op == 4) {

            for (size_t i = 0; i < usuarios.size(); i++) {

                 if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                     Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                     cout  << i << " Interno: " ;
                     cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;

                 }

                 if (dynamic_cast<Supervisor*> (usuarios.at(i))!=NULL){
                     Supervisor* temp = dynamic_cast<Supervisor*> (usuarios.at(i));
                     cout <<  i <<"  Supervisor: " ;
                     cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getEntradas() << endl;
                 }

            }

        }

        if (op == 4) {
            int select;

            std::cout << "Lista de Internos y Supervisores" << std::endl;
            for (size_t i = 0; i < usuarios.size(); i++) {

                 if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                     Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                     cout  << i << " Interno: " ;
                     cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;
                 }

                 if (dynamic_cast<Supervisor*> (usuarios.at(i))!=NULL){
                     Supervisor* temp = dynamic_cast<Supervisor*> (usuarios.at(i));
                     cout <<  i <<"  Supervisor: " ;
                     cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getEntradas() << endl;
                 }
            }

            std::cout << "¿A quien desea eliminar?" << std::endl;
            cin>>select;

            usuarios.erase(usuarios.begin() + select);
            std::cout << "" << std::endl;


        }
    }
        logeado = NULL;
        guardarDatos();

        ingresar();



}

void menuInterno(){

    int op = 0 ;
    while( op != 3){
        cout<<"   MENU"<<endl;
        cout<<"1. Listar Internos"<<endl;
        std::cout << "2. Elminar internos" << std::endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>> op ;


        if (op == 1) {
                std::cout << "Lista de Internos" << std::endl;

                for (size_t i = 0; i < usuarios.size(); i++) {
                     if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                         Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                         cout  << i << " Interno: " ;
                         cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;
                     }
                }
                std::cout << "" << std::endl;
        }
        if (op ==2 ){
            int select ;
            std::cout << "Lista de Internos" << std::endl;

            for (size_t i = 0; i < usuarios.size(); i++) {
                 if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                     Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                     cout  << i << " Interno: " ;
                     cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;
                 }
            }

            std::cout << "¿A quien desea eliminar?" << std::endl;
            cin>>select;

            usuarios.erase(usuarios.begin() + select);
            std::cout << "" << std::endl;
        }
}
    logeado = NULL;
    guardarDatos();

    ingresar();
}


void menuSupervisor(){
    int op = 0 ;
    while( op != 2){
        cout<<"   MENU"<<endl;
        cout<<"1. Listar Usuarios"<<endl;
        cout<<"2. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>> op ;


        if (op == 1) {
                std::cout << "Lista de Usuarios" << std::endl;

                for (size_t i = 0; i < usuarios.size(); i++) {

                     std::cout<< i << ":  "<<  usuarios.at(i)->getName() << std::endl;

                     if (dynamic_cast<Admin*> (usuarios.at(i))!=NULL){
                         Admin* temp = dynamic_cast<Admin*> (usuarios.at(i));
                         cout << i << " Admin: " ;
                         cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDate() << endl;
                     }

                     if (dynamic_cast<Manager*> (usuarios.at(i))!=NULL){
                         Manager* temp = dynamic_cast<Manager*> (usuarios.at(i));
                         cout <<  i << " Manager: " ;
                         cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getSalary() << endl;

                     }

                     if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                         Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                         cout  << i << " Interno: " ;
                         cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;

                     }

                     if (dynamic_cast<Supervisor*> (usuarios.at(i))!=NULL){
                         Supervisor* temp = dynamic_cast<Supervisor*> (usuarios.at(i));
                         cout <<  i <<"  Supervisor: " ;
                         cout<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getEntradas() << endl;
                     }

                }
                std::cout << "" << std::endl;
        }

    }
        logeado = NULL;
        guardarDatos();

        ingresar();
}


void menuAdmin(){

    int op = 0 ;

    while( op != 6){
        cout<<"   MENU"<<endl;
        cout<<"1. Crear Supervisor"<<endl;
        cout<<"2. Crear Manager"<<endl;
        cout<<"3. Crear Interno"<<endl;
        cout<<"4. Eliminar"<<endl;
        cout<<"5. Listar" << std::endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>> op ;

        string nombre;
        string correo;
        string contra;
        string fechain;


        double salario;
        //int diastrabajados;

        if (op == 1) {
            std::cout << "Ingrese el nombre: " << std::endl;
            cin >> nombre;
            std::cout << "Ingrese el correo: " << std::endl;
            cin >> correo;
            std::cout << "Ingrese la contraseña: " << std::endl;
            cin >> contra;

            usuarios.push_back(new Supervisor(nombre,correo,contra,1) );

        }

        if (op == 2) {
            std::cout << "Ingrese el nombre: " << std::endl;
            cin >> nombre;
            std::cout << "Ingrese el correo: " << std::endl;
            cin >> correo;
            std::cout << "Ingrese la contraseña: " << std::endl;
            cin >> contra;
            std::cout << "Ingrese el salario: " << std::endl;
            cin >> salario;
            usuarios.push_back(new Manager(nombre,correo,contra,salario) );

        }

        if (op == 3) {
            std::cout << "Ingrese el nombre: " << std::endl;
            cin >> nombre;
            std::cout << "Ingrese el correo: " << std::endl;
            cin >> correo;
            std::cout << "Ingrese la contraseña: " << std::endl;
            cin >> contra;

            usuarios.push_back(new Intern(nombre,correo,contra,1));

        }

        if (op == 4) {
                std::cout << "Lista de Usuarios" << std::endl;
                for (size_t i = 0; i < usuarios.size(); i++) {
                     std::cout<< i << ":  "<<  usuarios.at(i)->getName() << std::endl;
                }
                std::cout << "" << std::endl;
        }

        if (op == 5) {
            int select;
            std::cout << "Lista de Usuarios" << std::endl;

            for (size_t i = 0; i < usuarios.size(); i++) {
                 std::cout << i << ":  "<<  usuarios.at(i)->getName() << std::endl;
            }

            std::cout << "" << std::endl;
            std::cout << "¿A quien desea eliminar?" << std::endl;
            std::cin >> select;

            if ( usuarios.at(select) == usuarios.at(0)){
                std::cout << "No se pueden borrar administradores" << std::endl;
            }


            usuarios.erase(usuarios.begin() + select);
            std::cout << "" << std::endl;
        }
    }
        logeado = NULL;
        guardarDatos();
        ingresar();

}



void ingresar(){

    while(true){
       string nombre;
       string pass;

       std::cout << " Ingrese el nombre del usuario :" << std::endl;
       cin>> nombre;
       std::cout << " Ingrese la contraseña :" << std::endl;
       cin >> pass;

       bool verify = false;

       for (int i = 0; i < usuarios.size(); i++) {
           if (usuarios.at(i)->getPassword() == pass  && usuarios.at(i)->getName() == nombre ) {
               verify = true;
               logeado  = usuarios.at(i);
           }
       }

       if (verify == true) {
           std::cout << "El usuario ha ingresado con éxito" << std::endl;
           break;
       } else {
           std::cout << "Intente de nuevo" << std::endl;
       }
   }


   if (dynamic_cast<Admin*> (logeado)!=NULL){
       menuAdmin();
   }

   if (dynamic_cast<Manager*> (logeado)!=NULL){
       menuManager();
   }

   if (dynamic_cast<Intern*> (logeado)!=NULL){
       menuInterno();
   }

   if (dynamic_cast<Supervisor*> (logeado)!=NULL){
       menuSupervisor();
   }


}



void guardarDatos( ){

    ofstream admin;
    ofstream manager;
    ofstream intern;
    ofstream supervisor;

    admin.open ("Admins.txt");
    manager.open ("Managers.txt");
    intern.open ("Interns.txt");
    supervisor.open ("Supervisors.txt");


    //myfile << "Writing this to a file.\n";

        for (size_t i = 0; i < usuarios.size(); i++) {

            if (dynamic_cast<Admin*> (usuarios.at(i))!=NULL){
                Admin* temp = dynamic_cast<Admin*> (usuarios.at(i));
                admin<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDate() << endl;

            }

            if (dynamic_cast<Manager*> (usuarios.at(i))!=NULL){
                Manager* temp = dynamic_cast<Manager*> (usuarios.at(i));
                manager<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getSalary() << endl;


            }

            if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                intern<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getDaysWorked() << endl;

            }

            if (dynamic_cast<Supervisor*> (usuarios.at(i))!=NULL){
                Supervisor* temp = dynamic_cast<Supervisor*> (usuarios.at(i));
                supervisor<< temp->getName()<<";"<< temp->getEmail() <<";"<<temp->getPassword() << ";"<< temp->getEntradas() << endl;
            }
        }

        /*
     ofstream myfile;
     myfile.open ("example.txt");
     myfile << "Writing this to a file.\n";
     */

     admin.close ();
     manager.close ();
     intern.close ();
     supervisor.close ();

}

void cargarDatos(){

string token;
//ifstream file("file.txt");

    ifstream admin;
    admin.open("Admins.txt");
    ifstream manager("Managers.txt");
    ifstream intern("Interns.txt");
    ifstream supervisor("Supervisors.txt");

    ifstream file;

//    file.open("Admins.txt");
    string line;

    while(!admin.eof()){

    getline(admin,line);
    //std::cout << line << std::endl;
        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        //partir en tokens
        string nombre;
        string correo;
        string contra;
        string fecha;

        if(admin.fail()){
            std::cout << "falla" << std::endl;
        }else{
            getline(admin,nombre,';');
            getline(admin,correo,';');
            getline(admin,contra,';');
            getline(admin,fecha,';');


            usuarios.push_back(new Admin(nombre,correo,contra,fecha));
        }
        //std::cout << nombre << std::endl;

}
    admin.close();



    while(!intern.eof()){

    getline(intern,line);
    //std::cout << line << std::endl;
        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        //partir en tokens
        string nombre;
        string correo;
        string contra;
        string fecha;

        if(intern.fail()){
            std::cout << "falla" << std::endl;
        }else{
            getline(intern,nombre,';');
            getline(intern,correo,';');
            getline(intern,contra,';');
            getline(intern,fecha,';');
        }
        double numero  = atof(fecha.c_str());
        usuarios.push_back(new Intern(nombre,correo,contra,numero));
    }
    intern.close();


    while(!manager.eof()){

    getline(manager,line);
    //std::cout << line << std::endl;
        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        //partir en tokens
        string nombre;
        string correo;
        string contra;
        string fecha;

        if(manager.fail()){
            std::cout << "falla" << std::endl;
        }else{
            getline(manager,nombre,';');
            getline(manager,correo,';');
            getline(manager,contra,';');
            getline(manager,fecha,';');
        }
        int numero  = atoi(fecha.c_str());
        usuarios.push_back(new Manager(nombre,correo,contra,numero));
    }
    manager.close();


    while(!supervisor.eof()){

    getline(supervisor,line);
    //std::cout << line << std::endl;
        std::string delimiter = ";";
        size_t pos = 0;
        std::string token;
        //partir en tokens
        string nombre;
        string correo;
        string contra;
        string fecha;

        if(supervisor.fail()){
            std::cout << "falla" << std::endl;
        }else{
            getline(supervisor,nombre,';');
            getline(supervisor,correo,';');
            getline(supervisor,contra,';');
            getline(supervisor,fecha,';');
        }
        int numero  = atoi(fecha.c_str());
        usuarios.push_back(new Supervisor(nombre,correo,contra,numero));
    }
    supervisor.close();

}
