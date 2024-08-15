#include<Controlador.hpp>


Controlador::Controlador(){}
Controlador::~Controlador(){}


void Controlador::crearFichaAtencion(shared_ptr<Cliente>cliente, shared_ptr<Vehiculo> vehiculo, shared_ptr<Servicio> servicio,string _fecha)
{
 auto ficha = make_shared<FichaAtencion>(cliente,vehiculo,servicio,_fecha);
fichasAtencion.push_back(ficha);
}


void Controlador::agregarClienteACola(shared_ptr<Cliente> cliente){
     colaClientes.push(cliente);
     
}

void Controlador::atenderServicios()
{
   int numClientes= colaClientes.size();
   for(int i=0; i< numClientes; i++){
    auto cliente = colaClientes.front();//obtiene el primer elemento.
    colaClientes.pop();
    cout << "Atendiendo al cliente: " << cliente->getNombre() << " " << cliente->getApellido() << endl;
    if (!colaClientes.empty()) 
        {
            auto proximoCliente = colaClientes.front();
            cout << "Proximo cliente: " << proximoCliente->getNombre() << endl;
            }
    }
}

void Controlador::mostrarListadoServicios(vector<shared_ptr<Servicio>> servicios)
{
    cout <<" **LISTA DE SERVICIOS** \n";
    for(unsigned int i = 0; i < servicios.size(); i++){
    
       cout << "Nombre: " << servicios[i]->getNombre() 
            << ", Costo: " << servicios[i]->getCosto() << endl;
    };

    cout << "-----------------------------------------------\n";
}

void Controlador::mostrarServiciosRealizados(){
    cout << " **SERVICIOS REALIZADOS** \n";
    for(unsigned int i=0; i < fichasAtencion.size();i++){
        cout << " Nombre y Apellido: " << fichasAtencion[i]->getCliente()->getNombre() 
        <<" "<< fichasAtencion[i]-> getCliente()->getApellido()
        << "\n Servicio: "<< fichasAtencion[i]->getServicio()->getNombre() << endl;

    };
    
     cout << "---------------------------------------------\n";
}
vector<shared_ptr<FichaAtencion>> Controlador::getFichasDeAtencion() {
    return fichasAtencion;
}