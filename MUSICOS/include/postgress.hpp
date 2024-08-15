#ifndef POSTGRESS_H
#define POSTGRESS_H

#include <iostream>
#include "IBaseDeDatos.hpp"

class Postgress : public IBaseDeDatos {
    public:
        void elegirBdDatos(std::string base) override;
};

#endif

