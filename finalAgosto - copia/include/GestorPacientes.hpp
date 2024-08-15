#ifndef GESTOR_PACIENTES_HPP
#define GESTOR_PACIENTES_HPP

#include <vector>
#include <queue>
#include <memory>
#include "Paciente.hpp"

using namespace std;

class GestorPacientes {
private:
    vector<shared_ptr<Paciente>> pacientes;
    queue<shared_ptr<Paciente>> colaEspera;

public:
    void altaPaciente(shared_ptr<Paciente>& paciente);
    shared_ptr<Paciente> buscarPaciente(int dni) const;
    void agregarPacienteACola(shared_ptr<Paciente>& paciente);
    void mostrarPacientesEnEspera() const;
};

#endif // GESTOR_PACIENTES_HPP
