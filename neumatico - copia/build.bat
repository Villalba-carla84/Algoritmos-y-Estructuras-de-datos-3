:: Compilo código objeto
g++ -Wall -std=c++11 -I.\include\ -c .\src\Vehiculo.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Cliente.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Controlador.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Servicio.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\FichaAtencion.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Menu.cpp
g++ -Wall -std=c++11 -I.\include\ -c main.cpp

:: Enlazo y genero el binario
g++ Vehiculo.o Cliente.o Controlador.o  Servicio.o  FichaAtencion.o  Menu.o main.o  -o app.exe

:: Limpio los códigos objeto
DEL .\*.o

