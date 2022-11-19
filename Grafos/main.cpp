#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

#define MAX 10005 
#define Nodo pair< int , int > 
#define INF 1<<30 

struct comparador {
    bool operator() ( const Nodo &a , const Nodo &b ) {
    }
};
vector< Nodo > ady[ MAX ]; 
int distancia[ MAX ];    
bool visitado[ MAX ];    
priority_queue< Nodo , vector<Nodo> , comparador > Q; /* cola de prioridades, la cual es similar a una cola solo que tiene
adicionalmente, una propiedad asignada; usamos el comparador definido para que el de menor valor este en el tope, el tope sería q*/
int V;                    
int previo[ MAX ];        


void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  
        visitado[ i ] = false; 
        previo[ i ] = -1;    
    }
}


void minimizacion( int actual , int adyacente , int peso ){
    
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso; 
        previo[ adyacente ] = actual;                        
        Q.push( Nodo( adyacente , distancia[ adyacente ] ) ); 
    }
}


void print( int destino ){
    if( previo[ destino ] != -1 )    
        print( previo[ destino ] );  
    printf("%d " , destino );       
}

void corto( int inicial ){
    init();
    Q.push( Nodo( inicial , 0 ) ); 
    distancia[ inicial ] = 0;      
    int actual , adyacente , peso; 
    while( !Q.empty() ){                
        actual = Q.top().first;            
        Q.pop();                           
        if( visitado[ actual ] ) continue; 
        visitado[ actual ] = true;         

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ 
            adyacente = ady[ actual ][ i ].first;   
            peso = ady[ actual ][ i ].second;        
            if( !visitado[ adyacente ] ){       
                minimizacion( actual , adyacente , peso ); 
            }
        }
    }


    printf( "\tDistancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("\tVertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }

    puts("\tPara hallar el camino mas corto del vertice de origen al vertice destino," );
    printf("\tIngrese el vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    print( destino );
    printf("\n");
}


int main(){
 int a;
 int E , origen, destino , peso , inicial;
 cout<<"\tBienvenido al programa de Grafos con algoritmo Dijkstra para hallar la distancia mas corta de un nodo o vertice al otro. "<<endl;
 cout<<"\tIngrese la cantidad de nodos y arcos que contendra el grafo. "<<endl;
 cout<<"\tingrese numero de nodos: ";
 scanf("%d", &V);
 cout<<"\tingrese numero de arcos: ";
 scanf("%d", &E);
 
 cout<<"\tIngresar El nodo o vertice de origen, su arista y la distancia o peso de un nodo a otro dejando un espacio entre cada numero "<<endl;
 for (int i=0; i<E; i++){
     scanf("%d %d %d" , &origen , &destino , &peso );
     ady[ origen ].push_back( Nodo( destino , peso ) ); //consideremos grafo dirigido
 }
     
    cout<<"\tIngrese el vertice inicial: "<<endl;
    scanf("%d" , &inicial );
    corto( inicial );
    return 0;
}