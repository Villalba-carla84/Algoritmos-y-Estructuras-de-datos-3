#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP
#include <iostream>
#include<memory>
#include<vector>
#include<queue>
#include<Trabajador.hpp>
#include<FichaAtencion.hpp>
   

   using namespace std;


class Controlador{

     private:
         vector<shared_ptr<FichaAtencion>> fichasAtencion;
         queue<shared_ptr<Trabajador>>colaTrabajador;
          vector<shared_ptr<Trabajador>> listaTrabajadores;
     public:
     Controlador();
     ~Controlador();

     void crearFichaTrab(shared_ptr<Trabajador>trabajador,string empresa,vector<string> respuestas, string controles);

     void agregarTrabACola(shared_ptr<Trabajador>trabajador);

     void atenderRevision();

     vector<shared_ptr<FichaAtencion>>mostrarFichaAtencion();

     void mostrarListadoTrab(shared_ptr<Trabajador>trabajador);



    
};

#endif