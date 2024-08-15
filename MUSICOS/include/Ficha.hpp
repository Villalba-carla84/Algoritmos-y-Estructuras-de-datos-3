#ifndef FICHA_H
#define FICHA_H


#include "Paciente.hpp"
#include "Atencion.hpp"
#include <vector>

class Ficha {
private:
    int idFicha;
    Paciente paciente;
    std::vector<Atencion> atenciones; 

public:
    Ficha();
    Ficha(int idFicha, Paciente paci, const std::vector<Atencion>& aten);       
    Paciente getPaciente() const; 
    std::vector<Atencion> getAtenciones() const;
    int getIdFicha() const;
    
};

#endif


