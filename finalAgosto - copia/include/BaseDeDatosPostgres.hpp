#ifndef BASE_DE_DATOS_POSTGRES_HPP
#define BASE_DE_DATOS_POSTGRES_HPP

#include <iostream>
#include <IBaseDeDatos.hpp>
#include <FichaAtencion.hpp>
#include <memory>
using namespace std;

class BaseDeDatosPostgres : public IBaseDeDatos {
public:
    void guardarFicha(shared_ptr<FichaAtencion> ficha)const override;
    
};

#endif // BASE_DE_DATOS_POSTGRES_HPP