#include <iostream>

using namespace std;

class Paquete
{
    public:
    int id;
    int peso;
    char destino;
    char origen;
    Paquete *seguiente;
};

void InsertarPaquete(Paquete *&lista, int idx, int pesx, char destinox, char origenx){ //crear la funcion insertar con un parameetro nodo puntero y por referencia y los otros parametros son datos que queremos agregar
    Paquete *new_paquete = new Paquete();// creamos un nuevo nodo y asignamos memoria a la lista
    new_paquete->id = idx;               //asignamos los datos que nos manda el usuario al los campos de nuestro nodo  
    new_paquete->peso = pesx;
    new_paquete->destino = destinox;
    new_paquete->origen = origenx;

    Paquete *aux1 = lista; // crear nodos auxiliares
    Paquete *aux2; // crear nodos auxiliares

    while((aux1 != NULL) && (aux1->id < idx)){

    }


}

int main(){
    Paquete *lista = NULL; //crear puntero lista y igualado a null


    return 0;
}