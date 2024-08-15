#include <Trabajador.hpp>

Trabajador::Trabajador(){}
Trabajador::~Trabajador(){}

Trabajador::Trabajador(string nombre, string apellido, int dni){
   
   nombre=nombre;
   apellido=apellido;
   dni=dni;
   
    }

string Trabajador::getNombre(){
   
   return nombre;
} 

string Trabajador::getApellido(){ 
   return apellido;
}

int Trabajador::getDni(){
   return dni;
}
