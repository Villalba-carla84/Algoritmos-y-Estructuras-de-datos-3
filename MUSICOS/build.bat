::Compilar los archivos fuente del controlador, modelo  e interfaces
g++ -Wall -std=c++11 -I.\include\ -c .\src\Controlador.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Atencion.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Ficha.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Mysql.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Paciente.cpp 
g++ -Wall -std=c++11 -I.\include\ -c .\src\Postgress.cpp

::Compilar el archivo fuente principal
g++ -Wall -std=c++11 -I.\include\ -c .\main.cpp

::Vincular los archivos objeto para crear la aplicación ejec
g++ Controlador.o Atencion.o Ficha.o Mysql.o Paciente.o Postgress.o main.o -o app.exe 


::Eliminar todos los archivos  .o generados durante la compilación
DEL .\*.o


::ejecutar
app.exe

