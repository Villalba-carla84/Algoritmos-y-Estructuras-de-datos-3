#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "GestorPacientes.hpp"
#include "GestorFichasAtencion.hpp"
#include "GestorBaseDeDatos.hpp"

class Controlador {
private:
    /*GestorPacientes gestorPacientes;
    GestorFichasAtencion gestorFichasAtencion;
    GestorBaseDeDatos gestorBaseDeDatos;*/

public:
    void altaPaciente(shared_ptr<Paciente>& paciente,shared_ptr<GestorPacientes> gestorPacientes);
    void crearFichaAtencion(shared_ptr<Paciente>& paciente,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos);
    void agregarAtencion(int idFicha, shared_ptr<Atencion>& atencion,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos);
    void mostrarFichaAtencion(int idFicha,shared_ptr<GestorFichasAtencion> gestorFichasAtencion);
    void agregarPacienteACola(shared_ptr<Paciente>& paciente,shared_ptr<GestorPacientes> gestorPacientes);
    void mostrarPacientesEnEspera(shared_ptr<GestorPacientes> gestorPacientes);
    void seleccionarBaseDeDatos(const string& tipoBaseDeDatos,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos);
    shared_ptr<FichaAtencion> buscarFicha(int idFicha,shared_ptr<GestorFichasAtencion> gestorFichasAtencion);
    shared_ptr<Paciente> buscarPaciente(int dni,shared_ptr<GestorPacientes> gestorPacientes);
};

#endif // CONTROLADOR_HPP
