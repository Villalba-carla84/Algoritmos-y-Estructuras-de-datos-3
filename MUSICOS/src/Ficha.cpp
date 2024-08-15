#include "../include/Ficha.hpp"

Ficha::Ficha() {}

Ficha::Ficha(int idFicha, Paciente paci, const std::vector<Atencion>& atenciones) : idFicha(idFicha), paciente(paci), atenciones(atenciones) {}


Paciente Ficha::getPaciente() const {
    return paciente;
}

std::vector<Atencion> Ficha::getAtenciones() const {
    return atenciones;
}

int Ficha::getIdFicha() const {
    return idFicha;
}

