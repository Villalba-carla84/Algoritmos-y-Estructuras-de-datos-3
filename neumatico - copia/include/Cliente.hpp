#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>
using namespace std;


class Cliente{
  private:
      string nombre;
      string apellido;
      int dni;


  public:
     Cliente();
     ~Cliente();
     Cliente(string _nombre, string _apellido,int dni);

     string getNombre();
     string getApellido();
     int getDni();


};












#endif 