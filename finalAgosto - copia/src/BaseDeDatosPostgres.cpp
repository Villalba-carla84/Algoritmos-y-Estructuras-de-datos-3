#include <BaseDeDatosPostgres.hpp>

void BaseDeDatosPostgres::guardarFicha( shared_ptr<FichaAtencion> ficha) const{
    cout << "Guardando ficha de atencion en Postgres, ID: " << ficha->getId() << endl;
   
}
