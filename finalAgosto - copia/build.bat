::Compilar los archivos fuente del controlador, modelo  e interfaces
g++ -Wall -std=c++11 -I.\include\ -c .\src\Controlador.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Atencion.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\FichaAtencion.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\BaseDeDatosMySQL.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Paciente.cpp 
g++ -Wall -std=c++11 -I.\include\ -c .\src\BaseDeDatosPostgres.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\GestorPacientes.cpp 
g++ -Wall -std=c++11 -I.\include\ -c .\src\GestorFichasAtencion.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\GestorBaseDeDatos.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\Menu.cpp 

::Compilar los archivos fuente principal
g++ -Wall -std=c++11 -I.\include\ -c  .\main.cpp

::Vincular los archivos objeto para crear la aplicación ejec
g++ Controlador.o Atencion.o FichaAtencion.o GestorFichasAtencion.o GestorBaseDeDatos.o BaseDeDatosMySQL.o Paciente.o GestorPacientes.o BaseDeDatosPostgres.o Menu.o main.o -o main.exe 


::Eliminar todos los archivos  .o generados durante la compilación
DEL .\*.o


::ejecutar
main.exe

