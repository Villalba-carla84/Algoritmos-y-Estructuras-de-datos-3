#include<Servicio.hpp>


Servicio::Servicio(){}
Servicio::~Servicio(){}

Servicio::Servicio(string _nombre,double _costo)
{
    nombre=_nombre;
    costo=_costo;
}

string Servicio::getNombre()
{
    return nombre;
}

double Servicio::getCosto()
{
    return costo;
}
