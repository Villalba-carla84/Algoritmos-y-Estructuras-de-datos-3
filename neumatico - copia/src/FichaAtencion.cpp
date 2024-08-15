#include <FichaAtencion.hpp>

FichaAtencion::FichaAtencion(){}
FichaAtencion::~FichaAtencion(){}

FichaAtencion::FichaAtencion(shared_ptr<Cliente> _cliente,shared_ptr<Vehiculo>_vehiculo,shared_ptr<Servicio>_servicio,string _fecha)
{
    cliente=_cliente;
    vehiculo=_vehiculo;
    servicio=_servicio;
    fecha=_fecha;
}


shared_ptr<Cliente> FichaAtencion :: getCliente()
{
    return cliente;
}

shared_ptr<Vehiculo> FichaAtencion :: getVehiculo()
{
    return vehiculo;
}

shared_ptr<Servicio> FichaAtencion :: getServicio()
{
    return servicio;
}

string FichaAtencion :: getFecha()
{
    return fecha;
}