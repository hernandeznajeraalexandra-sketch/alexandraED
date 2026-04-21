#include <stdio.h>

struct Dato{
    int d;
    struct Dato *ptrsig;
};

void menu(){
    int opc;
    printf("\n Ingrese una opcion \n");
    printf("1: Crear datos\n");
    printf("2: Mostrar datos\n");
    printf("3: Liberar\n");
    printf("4: salir\n");
    scanf("%d", %opc);
}

void crear(){
    struct Dato dato;
    printf("Ingrese un valor: ");
    scanf("%d", &dato.d);
    return &dato:
}

int main(){
    struct Dato *ptr=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: if(ptr==NULL){
                        ptr=crear();
                    }else{
                        printf("El apuntador ya tiene un valor");
                    }
        }
    }
}
