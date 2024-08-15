#ifndef ATENCION_HPP
#define ATENCION_HPP

#include <string>
#include <iostream>
using namespace std;

class Atencion {
private:
    int id;
    string descripcion;

public:
    Atencion();
    Atencion(int id,string& descripcion);
    int getId();
    string getDescripcion() ;
    
    void mostrarInformacion()  {
        cout << "Atencion: " << descripcion << endl;
    }

};
#endif // ATENCION_HPP
