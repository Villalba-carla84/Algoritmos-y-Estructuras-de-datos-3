#include <Paciente.hpp>

Paciente::Paciente(const int dni, const string& nombre,const  string& apellido){
    this->dni=dni;
    this->nombre=nombre;
    this-> apellido=apellido;
    }

int Paciente::getDni() {
    return dni;
    }
string Paciente::getNombre() {
    return nombre; 
    }
string Paciente::getApellido() { 
    return apellido;
    }