#ifndef ATENCION_H
#define ATENCION_H

#include <string>

class Atencion {
private:
    int idAtencion;
    std::string fechaAtencion;
    std::string descAtencion;

public:
    Atencion();
    Atencion(int idAtencion, std::string fechaAtencion, std::string descAtencion);
    int getIdAtencion() const;
    std::string getFechaAtencion() const;
    std::string getDescAtencion() const;

};
#endif

