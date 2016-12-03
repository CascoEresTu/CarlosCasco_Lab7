main: main.o User.o Admin.o Manager.o Intern.o Supervisor.o
	g++ main.o User.o Admin.o Manager.o Intern.o Supervisor.o -o main

main.o: main.cpp User.h Admin.h Manager.h Intern.h Supervisor.h
	g++ -c main.cpp

User.o: User.h User.cpp
	g++ -c User.cpp

Admin.o : Admin.h User.h Admin.cpp
	g++ -c Admin.cpp

Manager.o : Manager.h User.h Manager.cpp
	g++ -c Manager.cpp

Intern.o : Intern.h User.h Intern.cpp
	g++ -c Intern.cpp

Supervisor.o : Supervisor.h User.h Supervisor.cpp
		g++ -c Supervisor.cpp

clean:
	rm -f *.o main
