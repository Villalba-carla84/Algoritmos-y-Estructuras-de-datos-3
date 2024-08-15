#include "GestorBaseDeDatos.hpp"
#include "BaseDeDatosMySQL.hpp"
#include "BaseDeDatosPostgres.hpp"
#include <iostream>

void GestorBaseDeDatos::seleccionarBaseDeDatos(const string& tipoBaseDeDatos) {
    if (tipoBaseDeDatos == "1") {
        baseDeDato = make_shared<BaseDeDatosMySQL>();
    } else if (tipoBaseDeDatos == "2") {
        baseDeDato = make_shared<BaseDeDatosPostgres>();
    } else {
        cout << "Tipo de base de datos desconocido. Seleccione MySQL o Postgres.\n";
    }
}

void GestorBaseDeDatos::guardarFicha(const shared_ptr<FichaAtencion> ficha) {
    if (baseDeDato) {
        baseDeDato->guardarFicha(ficha);
    } else {
        cout << "No se ha seleccionado una base de datos.\n";
    }
}
