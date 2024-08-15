#include <Vehiculo.hpp>


Vehiculo::Vehiculo(){}
Vehiculo::~Vehiculo(){}

Vehiculo:: Vehiculo(string _marca, string _modelo, int _anio)
{
    marca= _marca;
    modelo=_modelo;
    anio= _anio;
}

string Vehiculo:: getMarca(){
    return marca;
}

string Vehiculo::getModelo(){
    return modelo;
}

int Vehiculo::getAnio(){
    return anio;
}