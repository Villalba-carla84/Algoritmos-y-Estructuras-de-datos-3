#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <Controlador.hpp>
using namespace std;


class Menu{
 public:
    void mostrarMenu(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos);

private:
    void crearFichaAtencion(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos,shared_ptr<GestorFichasAtencion> gestorFichasAtencion);
   
    void agregarAtencion(Controlador& controlador,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos);
    void agregarPacienteACola(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes);
    void mostrarPacientesEnEspera(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes);
    void mostrarFichaAtencion(Controlador& controlador,shared_ptr<GestorFichasAtencion> gestorFichasAtencion);
};

#endif