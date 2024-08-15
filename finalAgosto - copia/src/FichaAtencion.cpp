#include <FichaAtencion.hpp>

FichaAtencion::FichaAtencion(){}
FichaAtencion::FichaAtencion(int id,shared_ptr<Paciente> paciente){
this->id = id;
this->paciente=paciente;
    
}

void FichaAtencion::agregarAtencion(shared_ptr<Atencion> atencion) {
    atenciones.push_back(atencion);
}

int FichaAtencion::getId()  {
    return id; 
    }


shared_ptr<Paciente> FichaAtencion::getPaciente()  {
    return paciente;
}

const vector<shared_ptr<Atencion>>& FichaAtencion::getAtenciones() {
    return atenciones;
}