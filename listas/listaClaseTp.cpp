
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<string.h>
#define maxchar 50

using namespace std;


struct nodo{

    int dni;
    char nombres[maxchar]; 
    char apellidos[maxchar];
    char direccion[maxchar];
    int telefono;
    struct nodo *sgte;

};


typedef struct nodo *PLista;

/*--------------------- FUNCION MENU PRINCIPAL --------------------*/
void menu(void){

    cout<<"\n\t\t[    REGISTRO DE PACIENTES    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. REGISTRAR PACIENTE                          "<<endl;
    cout<<" 2. ELIMINAR DATOS DE PACIENTE                  "<<endl;
    cout<<" 3. ACTUALIZAR PACIENTES                        "<<endl;
    cout<<" 4. MOSTRAR LISTADO                             "<<endl;
    cout<<" 5. SALIR                                       "<<endl;

    cout<<"\n Ingrese opcion : ";
}


/*----------------- FUNCION PARA ACTUALIZAR UN DATO---------------*/
void menu_actualizar(void){

    cout<<"\n\t\t[    ESPECIFIQUE CAMPO A ACTUALIZAR    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. NOMBRES                       "<<endl;
    cout<<" 2. APELLIDOS                     "<<endl;
    cout<<" 3. DIRECCION                     "<<endl;
    cout<<" 4. TELEFONO                      "<<endl;
    cout<<" 5. SALIR                         "<<endl;

    cout<<"\n Ingrese opcion : ";
}


/*-------------------- FUNCION REGISTRAR PACIENTES ------------------*/
void registrar_pacientes(PLista &lista){

    PLista t,q = new(struct nodo);

    cout<<"\n\n\t\t[  REGISTRO  ]\n";
    cout<<"\t\t------------";
    cout<<"\n\tDATOS DEL PACIENTE ";
    cin.ignore();cout<<"\n\tdni:"; cin>>q->dni;
    cin.ignore();cout<<"\tNOMBRES:"; cin.getline(q->nombres,maxchar);
    cin.ignore();cout<<"\tAPELLIDOS:"; cin.getline(q->apellidos,maxchar);
    cin.ignore();cout<<"\tDIRECCION:"; cin.getline(q->direccion,maxchar);
    cin.ignore();cout<<"\tTELEFONO:"; cin>>q->telefono;

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

/*------------------------ FUNCION ELIMINAR PACIENTE ---------------------*/
void eliminar_paciente(PLista &lista){

    int cod;
    PLista q,t;
    q=lista;

    cout<<"\n\n\n\tELIMINAR UN PACIENTE";
    cout<<"\n\tINGRESE dni:"; cin>>cod;

    while(q!=NULL){

            if(q->dni==cod){

                if(q==lista)
                    lista=lista->sgte;

                else
                    t->sgte=q->sgte;

                delete(q);

                cout<<"\n\tREGISTRO ELIMINADO...!!!!!\n";

                return;

            }else {

                t=q;
                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tdni INCORRECTO...!!\n";

}


/*-------------------- FUNCION ACTUALIZAR PACIENTE -------------------*/
void actualizar_paciente(PLista lista){

    int cod, x;
    PLista q;
    q=lista;

    cout<<"\n\n\tACTUALIZAR REGISTRO DE PACIENTE";
    cout<<"\n\tINGRESE dni:"; cin>>cod;

    while(q!=NULL){

            if(q->dni==cod){
                system("cls");
                cout<<"\n\tDATOS DEL PACIENTE  ";
                cout<<"\n\t--------------------";
                cout<<"\n\tdni   : "<<q->dni<<endl;
                cout<<"\n\tNOMBRES  : "<<q->nombres<<endl;
                cout<<"\tAPELLIDOS: "<<q->apellidos<<endl;
                cout<<"\tDIRECCION: "<<q->direccion<<endl;
                cout<<"\tTELEFONO : "<<q->telefono<<endl;

                menu_actualizar();
                cin>>x;

                switch(x){

                    case 1: cout<<"\n\tINGRESE NOMBRES:";
                            cin.ignore(); cin.getline(q->nombres,maxchar);
                            break;

                    case 2: cout<<"\n\tINGRESE APELLIDOS:";
                            cin.ignore(); cin.getline(q->apellidos,maxchar);
                            break;

                    case 3: cout<<"\n\tINGRESE DIRECCION:";
                            cin.ignore(); cin.getline(q->direccion,maxchar);
                            break;

                    case 4: cout<<"\n\tINGRESE TELEFONO:";
                            cin>>q->telefono;
                            break;

                    default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

                }
                cout<<"\n\tREGISTRO ACTUALIZADO...!!!!!\n";

                return;

            }else {


                q=q->sgte;

        }

    }
    if(q==NULL)
        cout<<"\n\tdni INCORRECTO...!!\n";
}


/*---------------------- FUNCION MOSTRAR PACIENTE -------------------*/
void mostrar_pacientes(PLista q){

    int i=1;

    while(q!=NULL){

        cout<<"\n\tDATOS DEL PACIENTE ["<<i<<"] ";
        cout<<"\n\t------------------------";
        cout<<"\n\tdni   : "<<q->dni<<endl;
        cout<<"\n\tNOMBRES  : "<<q->nombres<<endl;
        cout<<"\tAPELLIDOS: "<<q->apellidos<<endl;
        cout<<"\tDIRECCION: "<<q->direccion<<endl;
        cout<<"\tTELEFONO : "<<q->telefono<<endl;

        q=q->sgte;

        i++;
    }

}


/*------------------------- FUNCION PRINCIPAL -------------------*/
int main(void){

    system("color 0a");

    PLista lista=NULL;

    int opcion;

    do{
            menu();
            cin>>opcion;

            switch(opcion){

                case 1: registrar_pacientes(lista);
                        break;

                case 2: if(lista==NULL){

                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";

                        }else{

                            eliminar_paciente(lista);

                        }
                        break;

                case 3: if(lista==NULL){

                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";

                        }else{

                            actualizar_paciente(lista);

                        }
                        break;

                case 4: if(lista==NULL){

                            cout<<"\n\tNo Hay Pacientes Registrados.....!!!!\n";

                        }else {

                            mostrar_pacientes(lista);

                        }
                        break;

            

                case 5: return 0;


                default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;

            }

            system("pause");  system("cls");

        }while(opcion!=5);

    system("pause");

    return 0;
}
