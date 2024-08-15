#ifndef MYSQL_H
#define MYSQL_H

#include <iostream>
#include "IBaseDeDatos.hpp"

class Mysql : public IBaseDeDatos {
    public:
        void elegirBdDatos(std::string base) override;
};

#endif

