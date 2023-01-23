#include <iostream>

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
    printf("\n--Paquete Agregado Correctamente--");
    system("pause");
}

void EliminarPaquete(){

}

void MostrarPaquete(){

}

void GuardarArchivo(){

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
    printf("\nSeleccione una opcion: ");
    cin>>opc;


        switch(opc){
            case 1:
                system("cls");

                int insertId;
                float insertPes;
                string insertDes;
                string insertOrig;

                printf("Inserte los datos del paquete: ");
                printf("\nId del Paquete: ");
                cin>>insertId;
                printf("\nPeso exacto del paquete: ");
                cin>>insertPes;
                printf("\nIngrese el destino que tendra el paquete: ");
                cin>>insertDes;
                printf("\nOrigen del paqute: ");
                cin>>insertOrig;
                InsertarPaquete(lista,insertId,insertPes,insertDes,insertOrig);
        }
    }while(opc < 6);

    return 0;
}
