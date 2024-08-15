#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Paciente {
private:
    int dni;
    string nombre;
    string apellido;
   
public:
    Paciente(const int dni,  const string& nombre, const string& apellido);
  

    int getDni() ;
    string getNombre() ;
    string getApellido() ;
    string mostrarInformacion()  {
            
        return "DNI: " + to_string(dni) + ", Nombre: " + nombre + ", Apellido: " + apellido;
     }
};

#endif // PACIENTE_HPP