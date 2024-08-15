#include "../include/Paciente.hpp"

Paciente::Paciente() : idPaciente(0), nombre("") {}

Paciente::Paciente(int idPac, std::string nom) : idPaciente(idPac), nombre(nom){}
int Paciente::getIdPaciente(){
    return idPaciente;
}

std::string Paciente::getNombre() {
    return nombre;
}

