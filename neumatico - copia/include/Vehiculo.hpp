#ifndef VEHICULO_HPP
#define VEHICULO_HPP
#include <iostream>
#include<string>


using namespace std;

class Vehiculo{
     private:

        string marca;
        string modelo;
        int anio;

     public:

        Vehiculo();
        ~Vehiculo();
        Vehiculo(string _marca, string _modelo,int _anio);


        string getMarca();
        string getModelo();
        int getAnio();




}








;
#endif