#ifndef FICHAATENCION_HPP
#define FICHAATENCION_HPP
#include <iostream>
#include<Vehiculo.hpp>
#include<Cliente.hpp>
#include<Servicio.hpp>
#include <memory>
#include<string>


using namespace std;
class FichaAtencion{

     private:
         shared_ptr<Cliente>cliente;
         shared_ptr<Vehiculo> vehiculo;
         shared_ptr<Servicio> servicio;
         string fecha;

     public:
         FichaAtencion();
         ~FichaAtencion();
         FichaAtencion(shared_ptr<Cliente> _cliente,shared_ptr<Vehiculo>_vehiculo,shared_ptr<Servicio>_servicio,string _fecha);

         shared_ptr<Vehiculo> getVehiculo();
         shared_ptr<Cliente> getCliente();
         shared_ptr<Servicio> getServicio();
         string getFecha();




};


#endif