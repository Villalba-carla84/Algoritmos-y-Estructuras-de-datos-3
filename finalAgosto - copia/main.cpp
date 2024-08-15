#include <Menu.hpp>

int main() {

shared_ptr<GestorPacientes> gestorPacientes = make_shared<GestorPacientes>();
shared_ptr<GestorFichasAtencion> gestorFichasAtencion = make_shared<GestorFichasAtencion>();
shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos = make_shared<GestorBaseDeDatos>();
   Controlador controlador;
    Menu menu;
    menu.mostrarMenu(controlador,gestorPacientes, gestorFichasAtencion, gestorBaseDeDatos);
    return 0;
}
