#ifndef IBASE_DE_DATOS_HPP
#define IBASE_DE_DATOS_HPP

#include "FichaAtencion.hpp"
using namespace std;

class IBaseDeDatos {
public:
    virtual void guardarFicha( shared_ptr<FichaAtencion> ficha) const = 0;
   

    virtual ~IBaseDeDatos()=default;
};
#endif // IBASE_DE_DATOS_HPP