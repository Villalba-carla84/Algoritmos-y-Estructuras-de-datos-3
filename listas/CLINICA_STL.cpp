#include <iostream>
#include<list>

using namespace std;

class Paciente
{
private:
    string _dni;
    string _nombre;
    string _apellido;
    string _direccion;

public:
    Paciente();
    Paciente(string dni, string nombre, string apellido, string direccion);
    string getinfoPaciente();
};

Paciente::Paciente()
{
    this->_dni = " ";
    this->_nombre = " ";
    this-> _apellido = " ";
    this->_direccion = " ";
}
Paciente::Paciente(string dni, string nombre, string apellido, string direccion)
{
    this->_dni = dni ;
    this->_nombre = nombre;
    this-> _apellido = apellido;
    this->_direccion = direccion;
}
string Paciente::getinfoPaciente()
{
    string infoPaciente;
    infoPaciente = "DNI: " + this->_dni + "\nNombre: " + this->_nombre + " \nApellido: " + this->_apellido + " \nDireccion: " + this->_direccion + "\n\n";
    return infoPaciente;
}
void mostrar_pacientes(list<Paciente*> list)
{
   std::list<Paciente*>::iterator iterator;
    cout << "~~~~~LISTADO DE PACIENTES~~~~~~~ " << endl;
    cout << "---------------------- " << endl;
    for (iterator = list.begin(); iterator != list.end(); ++iterator)
        std::cout << (*iterator)->getinfoPaciente() << std::endl;
}

void actualizar_paciente(list<Paciente*> *list, Paciente *anterior, Paciente *actual)
{
    std::list<Paciente *>::iterator iterator;
    for (iterator = list->begin(); iterator != list->end(); ++iterator)
    {
        if ((*iterator)->getinfoPaciente() == anterior->getinfoPaciente())
        {
            *iterator = actual;
            return;
        }
    }
    cout << "Paciente no encontrado." << endl;
}

int main()
{
    list<Paciente*> paciente_list;

    Paciente *paciente_1 = new Paciente("3098765", "Juan", "Perez", "Gascon 456");
    Paciente *paciente_2 = new Paciente("3032452", "Alicia", "Galo", "Luro 7811");
    Paciente *paciente_3 = new Paciente("56788974", "Alicia", "Moreau", "Francia 3231");
    Paciente *paciente_4 = new Paciente("42176453", "gonzalo", "Rolo", "Castelli 3442");
    Paciente *paciente_5 = new Paciente("4578902", "Alfredo", "Martinez", "Libertad 4513");


    cout << " CARGANDO PACIENTES... " << endl;
    paciente_list.push_back(paciente_1);
    paciente_list.push_back(paciente_2);
    paciente_list.push_back(paciente_3);
    paciente_list.push_back(paciente_4);
    paciente_list.push_back(paciente_5);

    mostrar_pacientes(paciente_list);
    cout << " " << endl;

    cout << "Eliminando paciente... " << endl;
    paciente_list.remove(paciente_1);

    mostrar_pacientes(paciente_list);
    std::cout << " " << std::endl;

    cout << "Actualizando pacientes... " << endl;
    actualizar_paciente(&paciente_list, paciente_3, paciente_5);

    mostrar_pacientes(paciente_list);
 system("pause");

 
    return 0;
}
