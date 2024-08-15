#include <Controlador.hpp>

void Controlador::altaPaciente(shared_ptr<Paciente>& paciente,shared_ptr<GestorPacientes> gestorPacientes) {
    gestorPacientes->altaPaciente(paciente);
}

void Controlador::crearFichaAtencion(shared_ptr<Paciente>& paciente,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos) {
    gestorFichasAtencion->crearFichaAtencion(paciente);
    auto ficha = gestorFichasAtencion->buscarFicha(gestorFichasAtencion->getFichas().size());
    gestorBaseDeDatos->guardarFicha(ficha);
}

void Controlador::agregarAtencion(int idFicha, shared_ptr<Atencion>& atencion,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos) {
    gestorFichasAtencion->agregarAtencion(idFicha, atencion);
    auto ficha = gestorFichasAtencion->buscarFicha(idFicha);
    gestorBaseDeDatos->guardarFicha(ficha);
}

void Controlador::mostrarFichaAtencion(int idFicha,shared_ptr<GestorFichasAtencion> gestorFichasAtencion) {
    gestorFichasAtencion->mostrarFichaAtencion(idFicha);
}

void Controlador::agregarPacienteACola(shared_ptr<Paciente>& paciente,shared_ptr<GestorPacientes> gestorPacientes) {
    gestorPacientes->agregarPacienteACola(paciente);
}

void Controlador::mostrarPacientesEnEspera(shared_ptr<GestorPacientes> gestorPacientes) {
    gestorPacientes->mostrarPacientesEnEspera();
}

void Controlador::seleccionarBaseDeDatos(const string& tipoBaseDeDatos,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos) {
    gestorBaseDeDatos->seleccionarBaseDeDatos(tipoBaseDeDatos);
}

shared_ptr<FichaAtencion> Controlador::buscarFicha(int idFicha,shared_ptr<GestorFichasAtencion> gestorFichasAtencion) {
    return gestorFichasAtencion->buscarFicha(idFicha);
}

shared_ptr<Paciente> Controlador::buscarPaciente(int dni,shared_ptr<GestorPacientes> gestorPacientes) {
    return gestorPacientes->buscarPaciente(dni);
}
