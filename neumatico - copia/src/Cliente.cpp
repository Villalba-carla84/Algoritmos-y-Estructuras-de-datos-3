#include <Cliente.hpp>

Cliente :: Cliente(){}
Cliente::~Cliente(){}

Cliente :: Cliente(string _nombre,string _apellido,int _dni)
{
    nombre= _nombre;
    apellido = _apellido;
    dni= _dni;
}

string Cliente::getNombre(){
    return nombre;
}

string Cliente :: getApellido(){
    return apellido;
}

int Cliente::getDni(){
    return dni;
}



