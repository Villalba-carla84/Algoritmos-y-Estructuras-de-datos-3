#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <vector>
#include <iostream>
#include "Paciente.hpp"
#include "Atencion.hpp"
#include "Ficha.hpp"
#include "IBaseDeDatos.hpp"

class Controlador
{
private:
    Ficha ficha;
    IBaseDeDatos* motorBd;
    std::vector<Paciente> pacientes;
    std::vector<Atencion> atenciones;
    std::vector<Ficha> fichas;

public:
    Controlador();
    void agregarPaciente(Paciente paci);
    void agregarAtencion(Atencion aten);
    void agregarFicha(int idPaciente, int idAtencion);
    void cargarFicha(int idPaciente, int idAtencion);
    void listarPacientes();
    void listarAtenciones();
    void elegirMotorBd();
    ~Controlador();

    std::vector<Paciente>& getPacientes();
    std::vector<Atencion>& getAtenciones();
    std::vector<Ficha>& getFichas();
    
};


#endif


