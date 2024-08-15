#include<Menu.hpp>
Controlador* controlador =new Controlador();

void Menu::MostrarMenu()
 {
    int opcion;
    do {
        cout << "\n***ART***:\n";
        cout <<"Menu:" << endl;
        cout << "1. Crear Ficha de Atencion\n";
        cout << "2. Agregar Cliente a la cola\n";
        cout << "3. Cargar atencion\n";
        cout << "4. Mostrar Listado de atencion de trabajadores\n";
        cout << "5. Mostrar trabajadores cargados\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

     switch (opcion) {
            case 1: { 
                cargarTrabajador();

            } 
                break;
            case 2: { 
                trabACola();

            } 
                break;
            case 3: {
                atencion();

            } 
            case 4: { 
              
                mostrarAtenciones();
            }
                break;
            case 5: { 
                  listadoTrab();

            } 
                break;
          
            default:
                        std::cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
                            break;
                        }
                    }
                while (opcion != 5);

}


void cargarTrabajador(){
    string nombreTrabajador,apellidoTrabajador,controles;
    string empresaTrab, pregunta1,pregunta2,pregunta3;;
    int dniTrabajador;

      cout << "Ingrese el nombre del trabajador: ";
    cin >> nombreTrabajador;
    cout << "Ingrese el apellido del trabajador: ";
    cin >> apellidoTrabajador;
    cout << "Ingrese el DNI del trabajador: ";
    cin >> dniTrabajador;
  
     auto trabajador = make_shared<Trabajador>(nombreTrabajador, apellidoTrabajador, dniTrabajador);

     cout <<"Empresa:";
     cin>> empresaTrab;
     cout <<" Preguntas:";
     cout <<"Antecedentes familiares de muerte subita si/no"<<endl;
     cin>> pregunta1;
  
     cout <<"Realiza actividades fisicas:si/no" <<endl;
     cin>> pregunta2;
     cout << "Tipo de control realizado:";
     respuestas.push_back(respuesta2);
     auto ficha= make_shared<FichaAtencion>(empresaTrab,pregunta1,pregunta2,pregunta3,controles)
     
     controlador->crearFichaTrab()





}
void trabACola();
void atencion();
void  mostrarAtenciones();
void listadoTrab();


