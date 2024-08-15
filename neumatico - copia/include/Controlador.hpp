#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP
#include<iostream>
#include<vector>
#include<queue>
#include<memory>

#include<FichaAtencion.hpp>


using namespace std;


class Controlador{
        private:
          vector<shared_ptr<FichaAtencion>> fichasAtencion;
          queue<shared_ptr<Cliente>>colaClientes;
        
        public:
           Controlador();
           ~Controlador();
           
           void crearFichaAtencion(shared_ptr<Cliente>cliente, shared_ptr<Vehiculo> vehiculo, shared_ptr<Servicio> servicio,string _fecha);
           
           void agregarClienteACola(shared_ptr<Cliente> cliente);

           void atenderServicios();

           void mostrarListadoServicios(vector<shared_ptr<Servicio>>servicios);

           void mostrarServiciosRealizados();
            
           vector<shared_ptr<FichaAtencion>> getFichasDeAtencion();




};



#endif