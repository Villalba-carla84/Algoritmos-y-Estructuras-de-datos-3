#include <iostream>
#include <vector>
#include "../include/Controlador.hpp"
#include "../include/Mysql.hpp"
#include "../include/postgress.hpp"

Controlador::Controlador() : motorBd(nullptr) {}

Controlador::~Controlador() {
    delete motorBd; 
    motorBd = nullptr; 
}

void Controlador::elegirMotorBd() {
    int opcion;
    do {
        std::cout << "Elegir almacenamiento:" << std::endl;
        std::cout << "  1. MySQL" << std::endl;
        std::cout << "  2. Postgress" << std::endl;
        std::cout << "  Seleccione una opción: ";
        std::cin >> opcion;

        delete motorBd;

        switch (opcion) {
            case 1:
                motorBd = new Mysql();
                break;
            case 2:
                motorBd = new Postgress();
                break;
            default:
                std::cerr << "Opción no válida. Seleccionando MySQL por defecto." << std::endl;
                motorBd = new Mysql(); 
                break;
        }
    } while (opcion != 1 && opcion != 2);
}  


//Agregar pacientes al vector
void Controlador::agregarPaciente(Paciente paci) {
    pacientes.push_back(paci);
}

void Controlador::agregarAtencion(Atencion aten) {
    atenciones.push_back(aten);
}

void Controlador::agregarFicha(int idPaciente, int idAtencion) {
    bool pacienteEncontrado = false;
    bool atencionEncontrada = false;

    Paciente paciente;
    std::vector<Atencion> atencionesEncontradas;

    // Elegir el motor de base de datos
    elegirMotorBd();

    //Buscar paciente
    for(auto& paci : pacientes){
        if(paci.getIdPaciente() == idPaciente) {
            paciente = paci;
            pacienteEncontrado = true;
            break;
        }
    }

    //verificar paciente
    if(!pacienteEncontrado) {
        std::cout << "Paciente no encontrado. Crear el alta de paciente. " << std::endl;
        return;
    }

    //Buscar atenciones
    for (auto& aten : atenciones) {
        if (aten.getIdAtencion() == idAtencion) {
            atencionesEncontradas.push_back(aten);
            atencionEncontrada = true;
        }
    }

    // Verificar atenciones, si no existen, crear ficha nueva
    if (!atencionEncontrada) {
        std::cout << "La atención no se encontró. Por favor, asegúrate de haber ingresado un ID de atención válido." << std::endl;
        return;
    }

    // Crear y agregar ficha al vector
    Ficha nuevaFicha(fichas.size() + 1, paciente, atencionesEncontradas);
fichas.push_back(nuevaFicha);

// Listar datos de la ficha creada
std::cout << "Ficha creada satisfactoriamente." << std::endl;
std::cout << "Datos de la ficha creada:" << std::endl;
std::cout << "ID de la ficha: " << nuevaFicha.getIdFicha() << std::endl;
std::cout << "Datos del paciente:" << std::endl;
std::cout << "ID: " << paciente.getIdPaciente() << std::endl;
std::cout << "Nombre: " << paciente.getNombre() << std::endl;

std::cout << "Atenciones recibidas:" << std::endl;
for (const auto& atencion : atencionesEncontradas) {
    std::cout << "ID de Atención: " << atencion.getIdAtencion() << std::endl;
    std::cout << "Fecha de Atención: " << atencion.getFechaAtencion() << std::endl;
    std::cout << "Descripción de Atención: " << atencion.getDescAtencion() << std::endl;
    std::cout << "-----------------------" << std::endl;
}
}


void Controlador::cargarFicha(int idPaciente, int idAtencion) {
        // Buscar paciente
        Paciente paciente;
        for (auto& paci : pacientes) {
            if (paci.getIdPaciente() == idPaciente) {
                paciente = paci;
                break;
            }
        }

        // Mostrar datos del paciente
        std::cout << "Datos del paciente:" << std::endl;
        std::cout << "ID: " << paciente.getIdPaciente() << std::endl;
        std::cout << "Nombre: " << paciente.getNombre() << std::endl;

        // Mostrar atenciones anteriores
        std::cout << "Atenciones anteriores:" << std::endl;
        for (const auto& ficha : fichas) {
            if (ficha.getPaciente().getIdPaciente() == idPaciente) {
                for(const auto& atencion : ficha.getAtenciones()) {
                    std::cout << "Fecha de Atención: " << atencion.getFechaAtencion() << std::endl;
                    std::cout << "Descripción de Atención: " << atencion.getDescAtencion() << std::endl;
                }
            }
        }


        // Solicitar datos de la nueva atención
        std::string fechaAtencion;
        std::string descAtencion;

        std::cout << "Ingrese la fecha de la atención (dd/mm/yyyy): ";
        std::cin >> fechaAtencion;
        std::cin.ignore(); 
        std::cout << "Ingrese la descripción de la atención: ";
        std::getline(std::cin, descAtencion);

        // Crear la nueva atención y agregarla al vector de atenciones
        Atencion nuevaAtencion(idAtencion, fechaAtencion, descAtencion);
        atenciones.push_back(nuevaAtencion);
    }


std::vector<Ficha>& Controlador::getFichas() {
    return fichas;
}


