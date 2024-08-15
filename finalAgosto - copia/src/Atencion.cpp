#include <Atencion.hpp>
Atencion::Atencion(){}

Atencion::Atencion(int id,string& descripcion){
    this->id=id;
    this->descripcion=descripcion; 

}
int Atencion::getId() {
    return id;
}
string Atencion::getDescripcion()  { 
    return descripcion;
}