#ifndef CONTROLADOR_BASE_DE_DATOS_HPP
#define CONTROLADOR_BASE_DE_DATOS_HPP

#include <memory>
#include "IBaseDeDatos.hpp"
#include "FichaAtencion.hpp"

using namespace std;

class GestorBaseDeDatos {
private:
    shared_ptr<IBaseDeDatos> baseDeDato;

public:
    void seleccionarBaseDeDatos(const string& tipoBaseDeDatos);
    void guardarFicha(const shared_ptr<FichaAtencion> ficha);
};

#endif // CONTROLADOR_BASE_DE_DATOS_HPP
