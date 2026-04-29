#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

int menu(){
    int opc;
    printf("\n ---MENU---\n");
    printf("1: Crear nuevo dato\n");
    printf("2: Mostrar los datos creados\n");
    printf("3: Liberar el ultimo nodo\n");
    printf("4: Salir.\n");
    scanf("%d",&opc);
    return opc;
}

struct Dato *nuevoDato(void){
   struct Dato *ptrTemp=NULL;
    int dato;
    ptrTemp = (struct Dato *) malloc(sizeof(struct Dato));

    if(ptrTemp==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        ptrTemp->d=dato;
        ptrTemp->ptrSig=NULL;
        return ptrTemp;
    }
}

void mostrar(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
    }else{
        ptrAux = *ptr;
        while(ptrAux != NULL){
            printf("Dato: %d\n",ptrAux->d);
            ptrAux = ptrAux->ptrSig;
        }
    }
}

void liberar(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
        return;
    }

    if((*ptr)->ptrSig == NULL){
        free(*ptr);
        *ptr = NULL;
    }else{
        ptrAux = *ptr;

        while(ptrAux->ptrSig->ptrSig != NULL){
            ptrAux = ptrAux->ptrSig;
        }

        free(ptrAux->ptrSig);
        ptrAux->ptrSig = NULL;
    }
    printf("Ultimo nodo eliminado\n");
    
}
void eliminar (struct Dato **ptr){
    struct Dato *ptrAux;

    ptrAux=*ptr;
    while(ptrAux !=NULL){
        ptrAux=ptrAux->ptrSig;
    }
    free(ptrAux->ptrSig);
        ptrAux->ptrSig=NULL;


}

int main(){
    struct Dato *ptr=NULL, *ptrTemp=NULL, *ptrAux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: 
                ptrTemp=nuevoDato();
                if(ptrTemp==NULL){
                    printf("Nuevo nodo no creado\n");
                }else{
                    if(ptr==NULL){
                        ptr=ptrTemp;
                    }else{
                        ptrAux=ptr;

                        while(ptrAux->ptrSig != NULL){
                            ptrAux = ptrAux->ptrSig;
                        }
                        ptrAux->ptrSig = ptrTemp;
                    }
                }
                break;

            case 2:
                mostrar(&ptr);
                break;

            case 3:
                liberar(&ptr);
                break;

            case 4:
                eliminar(&ptr);
                printf("Saliendo...\n");
                break;

        }
    }while(op!=4);
        return 0;
}  
