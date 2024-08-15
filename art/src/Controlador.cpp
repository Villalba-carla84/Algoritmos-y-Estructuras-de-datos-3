#include <Controlador.hpp>



Controlador::Controlador(){}
Controlador::~Controlador(){}

void Controlador::crearFichaTrab(shared_ptr<Trabajador>trabajador,string empresa, vector<string> respuestas,string controles)
{
    auto ficha= make_shared<FichaAtencion>(trabajador,empresa,respuestas,controles); 
    fichasAtencion.push_back(ficha);
}

void Controlador:: agregarTrabACola(shared_ptr<Trabajador>trabajador)
{
   colaTrabajador.push(trabajador);
}
void Controlador::  atenderRevision()
{
int numTrab= colaTrabajador.size();
   for(int i=0; i< numTrab; i++){
    auto trabajador = colaTrabajador.front();//obtiene el primer elemento.
    colaTrabajador.pop();
    cout << "Atendiendo al cliente: " << trabajador->getNombre() << " " << trabajador->getApellido() << endl;
    if (!colaTrabajador.empty()) 
        {
            auto proximoTrab = colaTrabajador.front();
            cout << "Proximo cliente: " << proximoTrab->getNombre() << endl;
            }
    }
}

vector<shared_ptr<FichaAtencion>> Controlador::mostrarFichaAtencion() {
    return fichasAtencion;
}
void Controlador:: mostrarListadoTrab(shared_ptr<Trabajador>trabajador)

{
 cout << "Listado de Trabajadores:\n";
        for (const auto& trabajador:listaTrabajadores ) {
            cout << "Nombre: " << trabajador->getNombre() << ", Apellido: " << trabajador->getApellido() << ", DNI: " << trabajador->getDni() << endl;
            // Aquí puedes mostrar más información del trabajador si es necesario
        }
    }
