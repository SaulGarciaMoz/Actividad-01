#include <iostream>
#include <stdlib.h>
#include <fsrteam>

using namespace std;

class Paquete
{
    public:
    int id;
    float peso;
    string destino;
    string origen;
    Paquete *siguiente;
};

void InsertarPaquete(Paquete *&lista, int idx, float pesx, string destinox, string origenx){ //crear la funcion insertar con un parameetro nodo puntero y por referencia y los otros parametros son datos que queremos agregar
    Paquete *new_paquete = new Paquete();// creamos un nuevo nodo y asignamos memoria a la lista
    new_paquete->id = idx;               //asignamos los datos que nos manda el usuario al los campos de nuestro nodo
    new_paquete->peso = pesx;
    new_paquete->destino = destinox;
    new_paquete->origen = origenx;

    Paquete *aux1 = lista; // crear nodos auxiliares
    Paquete *aux2; // crear nodos auxiliares

    while((aux1 != NULL) && (aux1->id < idx)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = new_paquete;
    }else{
        aux2->siguiente = new_paquete;
    }

    new_paquete->siguiente = aux1;
    system("cls");
    printf("\n--Paquete Agregado Correctamente--\n");
    system("pause");
}

void EliminarPaquete(Paquete *&lista, int elim){
    Paquete *aux_borrar;
    Paquete *anterior = NULL;
    aux_borrar = lista;

    while((aux_borrar != NULL) && (aux_borrar->id != elim)){
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if(aux_borrar == NULL){
        cout<<"No existe ese Paquete";
        system("pause");
    }else if(anterior == NULL){
        lista = lista->siguiente;
        delete aux_borrar;
        printf("\nPaquete Eliminado con Exito\n");
        system("pause");
    }else{
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;
        printf("\nPaquete Eliminado con Exito\n");
        system("pause");
    }
}

void MostrarPaquete(Paquete *lista){
    Paquete *actual = new Paquete();
    actual = lista;

    while(actual != NULL){
        cout<<"\nID: "<<actual->id;
        cout<<"\nPeso: "<<actual->peso;
        cout<<"\nDestino: "<<actual->destino;
        cout<<"\nOrigen: "<<actual->origen;
        cout<<"\n---------------------\n";
        actual = actual->siguiente;
    }
}

void GuardarArchivo(){
    ofstream Archivo;
    
    Archivo.open("Paquetes.txt",ios::out);
    
    if(Archivo.fail()){
        
    }
}

void RecuperarArchivo(){

}

void Menu();

int main(){
    Paquete *lista = NULL; //crear puntero lista y igualado a null
    int opc;
    do{
    system("cls");
    printf("\n-----Menu-----");
    printf("\n1) Agregar un nuevo Paquete");
    printf("\n2) Eliminar Paquete");
    printf("\n3) Mostrar todos los Paquetes");
    printf("\n4) Guardar");
    printf("\n5) Recuperar");
    printf("\n6) Salir");
    printf("\nSeleccione una opcion: ");
    cin>>opc;


        switch(opc){
            case 1:
                {
                system("cls");

                int insertId;
                float insertPes;
                string insertDes;
                string insertOrig;

                printf("Inserte los datos del paquete: ");
                printf("\nID del Paquete: ");
                cin>>insertId;
                printf("\nPeso exacto del paquete: ");
                cin>>insertPes;
                printf("\nIngrese el destino que tendra el paquete: ");
                cin>>insertDes;
                printf("\nOrigen del paqute: ");
                cin>>insertOrig;
                InsertarPaquete(lista,insertId,insertPes,insertDes,insertOrig);
                }
                break;
            case 2:
                system("cls");
                int eliminar;
                if(lista == NULL){
                    printf("La Lista esta vacia, ingrese paquetes primero\n");
                    system("pause");
                }else{
                MostrarPaquete(lista);
                printf("\nEscriba el ID del paquete que desea eliminar: ");
                cin>>eliminar;
                EliminarPaquete(lista,eliminar);
                }
                break;

            case 3:
                system("cls");
                if(lista == NULL){
                    printf("La Lista esta vacia, ingrese paquetes primero\n");
                    system("pause");
                }else{
                MostrarPaquete(lista);
                system("pause");
                }
                break;
            
            case 4:
                
                break;

        }

    }while(opc < 6);

    return 0;
}
