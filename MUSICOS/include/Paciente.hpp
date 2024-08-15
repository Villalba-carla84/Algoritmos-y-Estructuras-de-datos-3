#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>

class Paciente {
private:
    int idPaciente;
    std::string nombre;

public:
    Paciente();
    Paciente(int idPaciente, std::string nombre);
    int getIdPaciente();
    std::string getNombre();
};

#endif

