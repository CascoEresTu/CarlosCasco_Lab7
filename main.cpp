#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <iostream>
#include <fstream>
#include <istream>

#include <vector>
#include <typeinfo>

using namespace std;

void guardarDatos(vector<User*> usuarios ){

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
                admin<< temp->getName()<<"\n"<< temp->getEmail() <<"\n"<<temp->getPassword() << "\n"<< temp->getDate() << endl;

            }

            if (dynamic_cast<Manager*> (usuarios.at(i))!=NULL){
                Manager* temp = dynamic_cast<Manager*> (usuarios.at(i));
                manager<< temp->getName()<<"\n"<< temp->getEmail() <<"\n"<<temp->getPassword() << "\n"<< temp->getSalary() << endl;


            }

            if (dynamic_cast<Intern*> (usuarios.at(i))!=NULL){
                Intern* temp = dynamic_cast<Intern*> (usuarios.at(i));
                intern<< temp->getName()<<"\n"<< temp->getEmail() <<"\n"<<temp->getPassword() << "\n"<< temp->getDaysWorked() << endl;

            }

            if (dynamic_cast<Supervisor*> (usuarios.at(i))!=NULL){
                Supervisor* temp = dynamic_cast<Supervisor*> (usuarios.at(i));
                supervisor<< temp->getName()<<"\n"<< temp->getEmail() <<"\n"<<temp->getPassword() << "\n"<< temp->getEntradas() << endl;
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

void cargarDatos(vector<User*> usuarios){

    ifstream admin;
    ifstream manager;
    ifstream intern;
    ifstream supervisor;


    std::cout << "bump" << std::endl;

}


int main(int argc, char const *argv[]) {
    vector <User*> usuarios;
    Admin* Juan = new Admin("Juan","cgc@asd.com","kakaroto", "Martes");
    Admin* pJuan = new Admin("Juan","cgc@asd.com","kakaroto", "Martes");

    usuarios.push_back(Juan);
    usuarios.push_back(pJuan);

    std::cout << "hola" << std::endl;
    guardarDatos(usuarios);

    return 0;
}
