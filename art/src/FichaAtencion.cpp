#include <FichaAtencion.hpp>



FichaAtencion::FichaAtencion(){}
FichaAtencion::~FichaAtencion(){}

FichaAtencion::FichaAtencion(shared_ptr <Trabajador> trabajador,string empresa, vector<string> respuestas,string controles)
{
    trabajador = trabajador;
    empresa = empresa;
    respuestas = respuestas;
    controles= controles;
}

