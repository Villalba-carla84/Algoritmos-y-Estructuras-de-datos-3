#ifndef IBASEDEDATOS_H
#define IBASEDEDATOS_H

#include <string>

class IBaseDeDatos {
    public:
        virtual void elegirBdDatos(std::string base) = 0;
        virtual ~IBaseDeDatos() {}
};

#endif

