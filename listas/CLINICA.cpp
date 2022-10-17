#include<iostream>

#define maxchar 50

using namespace std;


struct nodo{
    int dni;
    char nombre[maxchar]; 
    char apellido[maxchar];
    char direccion[maxchar];
   
    struct nodo *sgte;
};
typedef struct nodo *PLista;

void menu(void){
    cout<<"\n\tREGISTRO DE PACIENTES\n";
    cout<<"\t---------------------\n\n";
    cout<<" 1. REGISTRAR PACIENTE"<<endl;
    cout<<" 2. ELIMINAR DATOS DE PACIENTE"<<endl;
    cout<<" 3. ACTUALIZAR PACIENTES"<<endl;
    cout<<" 4. MOSTRAR LISTADO"<<endl;
    cout<<" 5. SALIR"<<endl;

    cout<<"\n Ingrese opcion : ";
}

void menu_actualizar(void){
    cout<<"\n\t\t    ESPECIFIQUE CAMPO A ACTUALIZAR \n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. NOMBRE"<<endl;
    cout<<" 2. APELLIDO"<<endl;
    cout<<" 3. DIRECCION"<<endl;
    cout<<" 4. SALIR"<<endl;

    cout<<"\n Ingrese opcion : ";
}

void registrar_pacientes(PLista &lista){
    PLista t,q = new(struct nodo);
    cout<<"\n\n\t\t  REGISTRO \n";
    cout<<"\t\t------------";
    cout<<"\n\tDATOS DEL PACIENTE ";
    cin.ignore();cout<<"\nDNI: "; cin>>q->dni;
    cin.ignore();cout<<"\nNOMBRE: "; cin.getline(q->nombre,maxchar);
    cin.ignore();cout<<"\nAPELLIDO: "; cin.getline(q->apellido,maxchar);
    cin.ignore();cout<<"\nDIRECCION: "; cin.getline(q->direccion,maxchar);
    

    system("cls");
    q->sgte = NULL;

    if(lista==NULL){
        lista = q;
    } else {
        t = lista;

        while(t->sgte!=NULL){
                t = t->sgte;
        }
        t->sgte = q;
    }
}

void eliminar_paciente(PLista &lista){
    int cod;
    PLista q,t;
    q=lista;

    cout<<"\n\n\n\t ELIMINAR UN PACIENTE ";
    cout<<"\n\n\tINGRESE dni:"; cin>>cod;
    while(q!=NULL){
            if(q->dni==cod){
                if(q==lista)
                    lista=lista->sgte;
                else
                    t->sgte=q->sgte;
                delete(q);
                cout<<"\n\n\tREGISTRO ELIMINADO.\n";
                return;
            }else {
                t=q;
                q=q->sgte;
        }
    }
    if(q==NULL)
        cout<<"\n\tdni INCORRECTO...\n";
}

void actualizar_paciente(PLista lista){
    int cod, x;
    PLista q;
    q=lista;

    cout<<"\n\n\n\tACTUALIZAR REGISTRO DE PACIENTE";
    cout<<"\n\n\tINGRESE dni:"; cin>>cod;
    while(q!=NULL){
            if(q->dni==cod){
                system("cls");
                cout<<"\n\t DATOS DEL PACIENTE  ";
                cout<<"\n\t--------------------";
                cout<<"DNI: "<<q->dni<<endl;
                cout<<"NOMBRE: "<<q->nombre<<endl;
                cout<<"APELLIDO: "<<q->apellido<<endl;
                cout<<"DIRECCION: "<<q->direccion<<endl;
              

                menu_actualizar();
                cin>>x;

                switch(x){
                    case 1: cout<<"\nINGRESE NOMBRE: ";
                            cin.ignore(); cin.getline(q->nombre,maxchar);
                            break;

                    case 2: cout<<"\nINGRESE APELLIDO: ";
                            cin.ignore(); cin.getline(q->apellido,maxchar);
                            break;

                    case 3: cout<<"\nINGRESE DIRECCION: ";
                            cin.ignore(); cin.getline(q->direccion,maxchar);
                            break;

                   

                    default: cout<<"\nINGRESE UNA OPCION VALIDA.\n"; break;

                }
                cout<<"\n\n\tREGISTRO ACTUALIZADO.\n";

                return;
            }else {
                q=q->sgte;
        }
    }

    if(q==NULL)
        cout<<"\n\tdni INCORRECTO.\n";
}

void mostrar_pacientes(PLista q){
    int i=1;
    while(q!=NULL){
        cout<<"\n\tDATOS DEL PACIENTE ["<<i<<"] ";
        cout<<"\n\t------------------------";
        cout<<"DNI: "<<q->dni<<endl;
        cout<<"NOMBRE: "<<q->nombre<<endl;
        cout<<"APELLIDO: "<<q->apellido<<endl;
        cout<<"DIRECCION: "<<q->direccion<<endl;
        

        q=q->sgte;

        i++;
    }

}

int main(void){
    PLista lista=NULL;
    int opcion;
    do{
            menu();
            cin>>opcion;

            switch(opcion){
                case 1: registrar_pacientes(lista);
                        break;

                case 2: if(lista==NULL){
                            cout<<"\n\tNo Hay Pacientes Registrados.\n";
                        }else{
                            eliminar_paciente(lista);
                        }
                        break;

                case 3: if(lista==NULL){
                            cout<<"\n\tNo Hay Pacientes Registrados.\n";
                        }else{
                            actualizar_paciente(lista);
                        }
                        break;

                case 4: if(lista==NULL){
                            cout<<"\n\tNo Hay Pacientes Registrados.\n";
                        }else {
                            mostrar_pacientes(lista);
                        }
                        break;

                case 5: return 0;
                default: cout<<"\nINGRESE UNA OPCION VALIDA.\n"; break;
            }

            system("pause");  system("cls");

        }while(opcion!=6);

    system("pause");


    return 0;
}
