#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

struct Punto{
    int x,y;
};

void leerDatos(struct Punto punto[10]){
    for(int i=0; i<10; i++){
        punto[i].x=rand()%9+1;
        punto[i].y=rand()%9+1;
    }
}
void mostrarDatos(struct Punto punto[10]){
    for(int i=0; i<10; i++){
        printf("\nDato %d", i);
        printf("\nX: %d", punto[i].x);
        printf("\nY: %d", punto[i].y);
    }
}
void distancia(struct Punto punto[10]){
    int dx, dy;
    float d;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<10; j++){
            dx=punto[i].x-punto[j].x;
            dx *= dx;
            dy= punto[i].y-punto[j].y;
            dy *= dy;
            d=sqrt(dx+dy);
        }
    }

    printf("La distancia es: %f", d);
}

int main(){
    struct Punto punto[10], *ptr;
    ptr=punto;
    int op=0;

    srand(time(NULL));
    
    do{
        printf("\n Ingrese un opcion: \n");
        printf("1: Leer Datos \n");
        printf("2: Mostrar datos \n");
        printf("3: Distancia\n");
        printf("4: salir\n");
        scanf("%d", &op);

        switch(op){
            case 1: leerDatos(punto);
                    break;
            case 2: mostrarDatos(punto);
                    break;
            case 3: distancia(punto);
                    break;
        }
    }while(op!=4);
}
