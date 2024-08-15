#include <iostream>
#include <queue>

#include "./include/Atencion.hpp"
#include "./include/Controlador.hpp"
#include "./include/Ficha.hpp"
#include "./include/IBaseDeDatos.hpp"
#include "./include/Mysql.hpp"
#include "./include/Paciente.hpp"
#include "./include/Postgress.hpp"

std::queue<Paciente> pacientesEnEspera;

Controlador controlador;
Atencion atencion;
//Mysql mysql;
//Postgress postgress;

int main() {
    system("cls");

     int opcion;
    do {
        std::cout << std::endl;
        std::cout << " Centro de Salud Comunitario y Social de Musicos " << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "      1. Nuevo paciente" << std::endl;
        std::cout << "      2. Nueva ficha" << std::endl;
        std::cout << "      3. Cargar ficha" << std::endl;
        std::cout << "      4. Mostrar ficha" << std::endl;
        std::cout << "      4. Mostrar pacientes en espera" << std::endl;
        std::cout << "      6. Salir" << std::endl;
        std::cout << std::endl;
        std::cout << "Ingrese opcion del menu: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                int idPaciente;
                std::string nombrePaciente;
                std::cout << "Ingrese ID del paciente: ";
                std::cin >> idPaciente;
                std::cin.ignore();
                std::cout << "Ingrese nombre del paciente: ";
                std::cin >> nombrePaciente;
                controlador.agregarPaciente(Paciente(idPaciente, nombrePaciente));
                break;
            }

            case 2: {
                int idAtencion, idPaciente;
                std::string fechaAtencion, descAtencion;
                std::cout << "Ingrese ID del oaciente: ";
                std::cin >> idPaciente;                
                std::cout << "Ingrese ID de la atención: ";
                std::cin >> idAtencion;
                std::cin.ignore();
                std::cout << "Ingrese fecha de la atención (dd/mm/yyyy): ";
                std::cin >> fechaAtencion;
                std::cout << "Ingrese descripción de la atención: ";
                std::cin >> descAtencion;
                controlador.agregarAtencion(Atencion(idAtencion, fechaAtencion, descAtencion));
                break;
            }
                
            case 3: {
                int idPaciente, idAtencion;
                std::cout << "Ingrese ID del paciente: ";
                std::cin >> idPaciente;
                std::cout << "Ingrese ID de la atención: ";
                std::cin >> idAtencion;
                controlador.agregarFicha(idPaciente, idAtencion);
                break;
            }
                
            case 4: {
                int idPaciente;
                std::cout << "Ingrese ID del paciente: ";
                std::cin >> idPaciente;

                // Buscar la ficha correspondiente en el controlador
                bool fichaEncontrada = false;
                for (const auto& ficha : controlador.getFichas()) {
                    if (ficha.getPaciente().getIdPaciente() == idPaciente) {
                        fichaEncontrada = true;
                        std::cout << "Ficha encontrada para el paciente con ID " << idPaciente << ":" << std::endl;
                        std::cout << "ID de la ficha: " << ficha.getIdFicha() << std::endl;
                        std::cout << "Nombre del paciente: " << ficha.getPaciente().getNombre() << std::endl;
                        std::cout << "Atenciones:" << std::endl;
                        for (const auto& atencion : ficha.getAtenciones()) {
                            std::cout << "  - ID de la atencion: " << atencion.getIdAtencion() << std::endl;
                            std::cout << "    Fecha de atencion: " << atencion.getFechaAtencion() << std::endl;
                            std::cout << "    Descripción de atencion: " << atencion.getDescAtencion() << std::endl;
                        }
                        break;
                    }
                }

                if (!fichaEncontrada) {
                    std::cout << "No se encontro ninguna ficha para el paciente con ID " << idPaciente << std::endl;
                }
                break;
            }
                            
            case 5: {
                // Mostrar pacientes en espera
                if (pacientesEnEspera.empty()) {
                    std::cout << "No hay pacientes en espera en este momento." << std::endl;
                } else {
                    std::cout << "Pacientes en espera:" << std::endl;
                    int count = 1;
                    while (!pacientesEnEspera.empty()) {
                        std::cout << count << ". " << pacientesEnEspera.front().getNombre() << std::endl;
                        pacientesEnEspera.pop();
                        count++;
                    }
                }
                break;
            }
                   
            case 6: {
                std::cout << "Saliendo del sistema..." << std::endl;
                std::cout << std::endl;
                break;
                default:
                std::cout << "Opcion no valida." << std::endl;
                break;
            }
                
        }
    } while (opcion != 6);



}
