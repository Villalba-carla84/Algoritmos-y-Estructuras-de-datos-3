#include "../include/Atencion.hpp"

Atencion::Atencion() {}

Atencion::Atencion(int idAte, std::string fechaAte, std::string descAte) : idAtencion(idAte), fechaAtencion(fechaAte), descAtencion(descAte){} ;
int Atencion::getIdAtencion() const {
    return idAtencion;
}

std::string Atencion::getFechaAtencion() const {
    return fechaAtencion;
}

std::string Atencion::getDescAtencion() const {
    return descAtencion;
}


