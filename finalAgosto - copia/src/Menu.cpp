#include <memory>
#include <vector>
#include <queue>
#include <Paciente.hpp>
#include <Atencion.hpp>
#include <FichaAtencion.hpp>
#include <Controlador.hpp>
#include <BaseDeDatosMySQL.hpp>
#include <BaseDeDatosPostgres.hpp>
#include <Menu.hpp>

void Menu::mostrarMenu(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos) {
    int opcion = 0;

    do {
        cout << "\n MENU:\n";
        cout << "1. Crear ficha de atencion\n";
        cout << "2. Agregar atencion\n";
        cout << "3. Agregar paciente a la cola de espera\n";
        cout << "4. Mostrar pacientes en espera\n";
        cout << "5. Mostrar ficha de atencion\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearFichaAtencion(controlador,gestorPacientes,gestorBaseDeDatos,gestorFichasAtencion);
                break;
            case 2:
                agregarAtencion(controlador,gestorFichasAtencion,gestorBaseDeDatos);
                break;
            case 3:
                agregarPacienteACola(controlador,gestorPacientes);
                break;
            case 4:
                mostrarPacientesEnEspera(controlador,gestorPacientes);
                break;
            case 5:
                mostrarFichaAtencion(controlador,gestorFichasAtencion);
                break;
            case 6:
                cout << "\n Saliendo del programa.\n";
                break;
            default:
                cout << "\n Opcion invalida. Por favor, ingrese una opcion valida.\n";
                break;
        }
    } while (opcion != 6);
}
void Menu::crearFichaAtencion(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos,shared_ptr<GestorFichasAtencion> gestorFichasAtencion) {
    int dni;
    string nombre, apellido;
    cout << "\nIngrese DNI: ";
    cin >> dni;
    cout << "Ingrese Nombre: ";
    cin >> nombre;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    auto paciente = make_shared<Paciente>(dni, nombre, apellido);
    controlador.altaPaciente(paciente,gestorPacientes);

    cout << "\n ***Alta de Paciente exitosa.***\n";

    string tipoBaseDeDatos;
    cout << "Seleccione tipo de base de datos donde quiere guardar el Paciente (MySQL(1)/Postgres(2)): ";
    cin >> tipoBaseDeDatos;
    controlador.seleccionarBaseDeDatos(tipoBaseDeDatos,gestorBaseDeDatos);
    paciente->mostrarInformacion();

    controlador.crearFichaAtencion(paciente,gestorFichasAtencion,gestorBaseDeDatos);
    cout << "\n*Ficha de atencion creada exitosamente*.\n";
}

void Menu::agregarAtencion(Controlador& controlador,shared_ptr<GestorFichasAtencion> gestorFichasAtencion,shared_ptr<GestorBaseDeDatos> gestorBaseDeDatos) {
    int idFicha;
    string descripcion;
    cout << "\n Ingrese ID de ficha de atencion: ";
    cin >> idFicha;

    auto ficha = controlador.buscarFicha(idFicha,gestorFichasAtencion);
    if (!ficha) {
        cout << "Ficha de atención no encontrada.\n";
        return;
    }
    cout << "Ingrese descripcion de la consulta: ";
    cin.ignore();
    getline(cin, descripcion);
    auto atencion = make_shared<Atencion>(idFicha, descripcion);
    controlador.agregarAtencion(idFicha, atencion,gestorFichasAtencion,gestorBaseDeDatos);
}

void Menu::agregarPacienteACola(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes) {
    int dni;
    cout << "\n Ingrese DNI del paciente: ";
    cin >> dni;
    auto paciente = controlador.buscarPaciente(dni,gestorPacientes);
    if (paciente) {
        controlador.agregarPacienteACola(paciente,gestorPacientes);
    } else {
        cout << "Paciente no encontrado.\n";
    }
}

void Menu::mostrarPacientesEnEspera(Controlador& controlador,shared_ptr<GestorPacientes> gestorPacientes) {
    controlador.mostrarPacientesEnEspera(gestorPacientes);
}

void Menu::mostrarFichaAtencion(Controlador& controlador, shared_ptr<GestorFichasAtencion> gestorFichasAtencion) {
    int idFicha;
    cout << "\n Ingrese ID de ficha de atencion: ";
    cin >> idFicha;
    controlador.mostrarFichaAtencion(idFicha,gestorFichasAtencion);
}

