#include <memory>
#include <vector>
#include <queue>
#include <Cliente.hpp>
#include <Vehiculo.hpp>
#include <Servicio.hpp>
#include <FichaAtencion.hpp>
#include <Controlador.hpp>
#include<Menu.hpp>



// Función para mostrar el menú
void Menu :: mostrarMenu(Controlador& controlador) {
    int opcion;
    do {
        cout << "\n***TALLER DE NEUMATICOS***:\n";
        cout <<"Menu:" << endl;
        cout << "1. Crear Ficha de Atencion\n";
        cout << "2. Agregar Cliente a la cola\n";
        cout << "3. Atender Servicios\n";
        cout << "4. Mostrar Listado de Servicios Disponibles\n";
        cout << "5. Mostrar Servicios Realizados\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
case 1: {
    string nombreCliente, apellidoCliente;
    string marcaVehiculo, modeloVehiculo ;
    string fecha;
    int dniCliente,anioVehiculo;

    
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;
    cout << "Ingrese el apellido del cliente: ";
    cin >> apellidoCliente;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dniCliente;

    
    auto cliente = make_shared<Cliente>(nombreCliente, apellidoCliente, dniCliente);

    
    cout << "Ingrese la marca del vehiculo: ";
    cin >> marcaVehiculo;
    cout << "Ingrese el modelo del vehiculo: ";
    cin >> modeloVehiculo;
    cout << "Ingrese el anio del vehiculo: ";
    cin >> anioVehiculo;

  
    auto vehiculo = make_shared<Vehiculo>(marcaVehiculo, modeloVehiculo, anioVehiculo);

    // Mostrar los servicios disponibles,crea un vector de punteros compartidos (shared_ptr)
    // a objetos Servicio, inicializando cada elemento del vector con un servicio diferente,
   //Luego, pasa este vector al método mostrarListadoServicios() del objeto controlador para mostrar los servicios disponibles.
   vector<shared_ptr<Servicio>> serviciosDisponibles = {
        make_shared<Servicio>("1-.Cambio de aceite", 25000.0),
        make_shared<Servicio>("2-.Revision de frenos", 18000.0),
        make_shared<Servicio>("3-.Cambio de neumaticos", 12000.0)
    };
    controlador.mostrarListadoServicios(serviciosDisponibles);

    // Solicitar al usuario que elija un servicio
    unsigned int opcionServicio;
    cout << "Seleccione un servicio: ";
    cin >> opcionServicio;

    // Validar la opción seleccionada por el usuario
    if (opcionServicio > 0 && opcionServicio <= serviciosDisponibles.size()) {
        // Obtener el servicio seleccionado
        auto servicio = serviciosDisponibles[opcionServicio - 1];

        // Solicitar al usuario que ingrese la fecha de atención
        cout << "Ingrese la fecha de atencion (DD-MM-AAAA): ";
       cin >> fecha;

        // Crear la ficha de atención y agregarla al controlador
        controlador.crearFichaAtencion(cliente, vehiculo, servicio, fecha);

       cout << "Ficha de atencion creada con exito.\n";
    } else {
        cout << "Opcion invalida. Por favor, seleccione una opcion valida.\n";
    }
    break;
}

case 2: {
    // Verificar si no hay fichas de atención creadas aún
    if (controlador.getFichasDeAtencion().empty()) {
       cout << "No hay clientes creados aun.\n";
        break;
    }

    
    cout << "Fichas de atencion creadas:\n";
     auto fichasDeAtencion = controlador.getFichasDeAtencion();
    for (size_t i = 0; i < fichasDeAtencion.size(); ++i) {
        auto cliente = fichasDeAtencion[i]->getCliente();
        cout << i + 1 << " Nombre: " << cliente->getNombre() 
                      << ", Apellido: " << cliente->getApellido() 
                      << ", DNI: " << cliente->getDni() << endl;
    }

    // Solicitar al usuario que seleccione una ficha de atención
    unsigned int opcionFicha;
    cout << "Seleccione una ficha de atencion: ";
    cin >> opcionFicha;

    // Validar la opción seleccionada por el usuario
    if (opcionFicha > 0 && opcionFicha <= fichasDeAtencion.size()) {
        // Obtener la ficha de atención seleccionada
        auto clienteSeleccionado = fichasDeAtencion[opcionFicha - 1]->getCliente();

        // Agregar el cliente a la cola de clientes del controlador de atención
        controlador.agregarClienteACola(clienteSeleccionado);

       cout << "Cliente agregado a la cola con exito.\n";
    } else {
       cout << "Opción invalida. Por favor, seleccione una opción valida.\n";
    }
    break;
}

case 3: {
               controlador.atenderServicios();
                break;
            }
case 4: {
                // Lógica para mostrar el listado de servicios disponibles
                vector<shared_ptr<Servicio>> serviciosDisponibles = {
                      make_shared<Servicio>("1-.Cambio de aceite", 25000.0),
                      make_shared<Servicio>("2-.Revision de frenos", 18000.0),
                      make_shared<Servicio>("3-.Cambio de neumaticos", 12000.0)
                };
                controlador.mostrarListadoServicios(serviciosDisponibles);
                break;
            }
case 5: {
                // Lógica para mostrar los servicios realizados
                controlador.mostrarServiciosRealizados();
                break;
            }
case 6: {
                std::cout << "Saliendo del programa.\n";
                break;
            }
default:
            std::cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
                break;
            }
        }
     while (opcion != 6);

}
