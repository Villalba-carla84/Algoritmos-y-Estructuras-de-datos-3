#include "GestorPacientes.hpp"
#include <algorithm>
#include <iostream>

void GestorPacientes::altaPaciente(shared_ptr<Paciente>& paciente) {
    pacientes.push_back(paciente);
}

shared_ptr<Paciente> GestorPacientes::buscarPaciente(int dni) const {
    auto it = find_if(pacientes.begin(), pacientes.end(),
                      [dni](const shared_ptr<Paciente>& paciente) {
                          return paciente->getDni() == dni;
                      });

    if (it != pacientes.end()) {
        return *it;
    } else {
        return nullptr; // Paciente no encontrado
    }
}

void GestorPacientes::agregarPacienteACola(shared_ptr<Paciente>& paciente) {
    colaEspera.push(paciente);
    cout << "Paciente agregado a la cola de espera.\n";
}

void GestorPacientes::mostrarPacientesEnEspera() const {
    if (colaEspera.empty()) {
        cout << "No hay pacientes en espera.\n";
        return;
    }

    queue<shared_ptr<Paciente>> colaTemp = colaEspera;
    cout << "Pacientes en espera:" << endl;
    while (!colaTemp.empty()) {
        auto paciente = colaTemp.front();
        colaTemp.pop();
        cout << "- " << paciente->getNombre() << " " << paciente->getApellido() << endl;
    }
}
