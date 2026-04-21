
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(){
    int n;
    printf("Seleccione una opcion \n");
    printf("1: Reservar memoria \n");
    printf("2: Ingresar datos \n");
    printf("3: Mostrar datos \n");
    printf("4: Liberar");
    printf("5: Salir");
    scanf("%d", &n);

    return n;
}

int* reservaMemoria(){
    int *ptrTemp;
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    ptrTemp=(int*)malloc(sizeof(int)*n);
    if(ptrTemp==NULL)
        printf("no se puede reservar memoria");

    return ptrTemp;
}

//Otra forma de reservar memoria
/*void reservaMemoria(int **ptr){   //reserva la direccion de memeoria de un dobleapuntador
      
}*/

void ingresar(int ptr){
    srand(time(NULL));
    for(int i=0; i<5; i++)
        ptr[i]=rand()%10;
}

void mostrar(){
    for(int j=0; j<5; j++)
        printf("%d \n", ptr[j]);
}

void liberar(int ptr){
    free(ptr);
}

int main(){
    int *ptr=NULL;
    int op;

    do{
        op=menu();
        
        switch(op){
            case 1: ptr=reservaMemoria(); //reservaMemoria(&ptr);
                    break;
            case 2: ingresar(ptr);
                    break;
            case 3: mostrar();
                    break;
            case 4: liberar(ptr);
                    break;
        }
    }while(op!=5);
}
