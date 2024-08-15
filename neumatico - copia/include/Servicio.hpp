#ifndef SERVICIO_HPP
#define SERVICIO_HPP
#include <iostream>
#include<string>


using namespace std;

class Servicio{

    private:
      string nombre;
      double costo;

    public:
       Servicio();
       ~Servicio();
       Servicio(string _nombre, double _costo);


       string getNombre();
       double getCosto();




};
#endif