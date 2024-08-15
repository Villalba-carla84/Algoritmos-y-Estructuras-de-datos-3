#ifndef FICHAATENCION_HPP
#define FICHAATENCION_HPP
#include <iostream>
#include<memory>
#include <Trabajador.hpp>
#include <vector>
using namespace std;


class FichaAtencion{

   private:
    shared_ptr<Trabajador>trabajador;
    string empresa;
    vector<string> respuestas;
    string controles;

   public:
    FichaAtencion();
    ~FichaAtencion();
    FichaAtencion(shared_ptr<Trabajador>trabajador,string empresa, vector<string> respuestas,string controles);

   void mostrarFicha();


    
};


#endif