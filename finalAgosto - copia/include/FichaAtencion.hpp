#ifndef FICHA_DE_ATENCION_HPP
#define FICHA_DE_ATENCION_HPP

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <Paciente.hpp>
#include <Atencion.hpp>
using namespace std;

class FichaAtencion {
private:
    int id;
    shared_ptr<Paciente> paciente;
    vector<shared_ptr<Atencion>> atenciones;
    

public:
    FichaAtencion();
    FichaAtencion(int id,shared_ptr<Paciente> paciente);
    void agregarAtencion(shared_ptr<Atencion> atencion);
    int getId() ;
    shared_ptr<Paciente> getPaciente() ;
    const vector<shared_ptr<Atencion>>& getAtenciones();
};
#endif // FICHA_DE_ATENCION_HPP