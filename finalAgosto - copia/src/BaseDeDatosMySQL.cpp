#include <BaseDeDatosMySQL.hpp>

void BaseDeDatosMySQL::guardarFicha( shared_ptr<FichaAtencion> ficha) const{
    cout << "Guardando ficha de atencion en MySQL, ID: "<<ficha->getId()<< endl;

}


