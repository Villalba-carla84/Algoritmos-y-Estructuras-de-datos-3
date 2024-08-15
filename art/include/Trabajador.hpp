#ifndef TRABAJADOR_HPP
#define TRABAJADOR_HPP
#include <iostream>
using namespace std;

class Trabajador{
    private:
       string nombre;
       string apellido;
       int dni;

    public:

       Trabajador();
       ~Trabajador();
       Trabajador(string nombre, string apellido,int dni);
        string getNombre();
        string getApellido();
        int getDni();
};


#endif