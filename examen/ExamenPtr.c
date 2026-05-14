#include <stdio.h>
#include <stdlib.h>

struct Dato {
    int n;
    struct Dato *Ptrant;
    struct Dato *Ptrsig;
};
 int menu(){
    int op;
        printf("\n---MENú---\n");
        printf("1 - Insertar nodo\n");
        printf("2 - Eliminar nodo\n");
        printf("3 - Mostrar nodo\n");
        printf("4 - Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &op);
        return op;
}

struct Dato *Ptrtemp = NULL;

void insertar(int dato) {
    struct Dato *Ptrnuevo;
    Ptrnuevo = (struct Dato*) malloc(sizeof(struct Dato));

    if(Ptrnuevo == NULL) {
        printf("Error no se pudo reservar memoria\n");
    }
    Ptrnuevo ->  n = dato;

    if(Ptrtemp == NULL) {

        Ptrnuevo -> Ptrsig = Ptrnuevo;
        Ptrnuevo -> Ptrant = Ptrnuevo;
        Ptrtemp = Ptrnuevo;
    }
    else {
        struct Dato *Ptraux;

        Ptraux = Ptrtemp -> Ptrant;
        Ptrnuevo-> Ptrsig = Ptrtemp;
        Ptrnuevo -> Ptrant = Ptraux;
        Ptraux -> Ptrsig = Ptrnuevo;
        Ptrtemp -> Ptrant = Ptrnuevo;
    }
}

void eliminar(int dato) {

    if(Ptrtemp == NULL) {
        printf("no hay nada en la lista):\n");
    }

    struct Dato *Ptraux;
    Ptraux = Ptrtemp;

    do {

        if(Ptraux -> n == dato) {
            if(Ptraux -> Ptrsig == Ptraux) {
                Ptrtemp = NULL;
            }
            else {
                Ptraux -> Ptrant -> Ptrsig = Ptraux -> Ptrsig;
                Ptraux -> Ptrsig -> Ptrant = Ptraux -> Ptrant;

                if(Ptraux == Ptrtemp) {
                    Ptrtemp = Ptraux -> Ptrsig;
                }
            }
            free(Ptraux);
        }
        Ptraux = Ptraux -> Ptrsig;

    } while(Ptraux != Ptrtemp);
    printf("No se encontro nada\n");
}

void mostrar() {
    if(Ptrtemp == NULL) {
        printf("Todavía no hay nada en lista\n");
    }

    struct Dato *Ptraux;
    Ptraux = Ptrtemp;
    printf("\n--DATOS--\n");

    do {
        printf("%d ->", Ptraux -> n);
        Ptraux = Ptraux -> Ptrsig;

    } while(Ptraux != Ptrtemp);
}

int main() {
    int op;
    int dato;

    do {
        op=menu();
        switch(op) {
            case 1:
                printf("Ingrese un dato: ");
                scanf("%d", &dato);
                insertar(dato);
                break;
            case 2:
                printf("Ingres el dato a eliminar:");
                scanf("%d",&dato);
                eliminar(dato);
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf("Saliendo...\n");     
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(op != 4);

    return 0;
}