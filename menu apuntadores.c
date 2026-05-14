#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

int menu(int opc){
    printf("\n ---MENU---\n");
    printf("1: Crear nuevo dato\n");
    printf("2: Funciones\n");
    printf("3: Mostrar los datos creados\n");
    printf("4: Liberar el ultimo nodo\n");
    printf("5: Salir.\n");
    scanf("%d",&opc);
    return opc;
}
int funcionesmenu(){
    int op2;
    printf("\n ---SUBMENU---\n");
    printf("1: Buscar dato\n");
    printf("2: Contar \n");
    printf("3: Remplazar\n");
    printf("4: Ordenar\n");
    printf("5: Regresar\n");
    scanf("%d",&op2);
    return op2;

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
        }
    else{ 
        if((*ptr)->ptrSig == NULL){
            free(*ptr);
            *ptr = NULL;
            }
        else{
            ptrAux = *ptr;
            while(ptrAux->ptrSig->ptrSig != NULL){
                ptrAux = ptrAux->ptrSig;
                }

            free(ptrAux -> ptrSig);
            ptrAux->ptrSig = NULL;
            }
            printf("Ultimo nodo eliminado\n");
        }
    
}
void eliminar (struct Dato **ptr){
    struct Dato *ptrAux;
    struct Dato *ptrTemp;
    
    if(*ptr == NULL){
        printf("No hay nodos\n");
        }
    else{ 
        ptrAux=*ptr;
        while(ptrAux !=NULL){
            ptrTemp=ptrAux;
            ptrAux=ptrAux->ptrSig;
            free(ptrTemp);
            }
        *ptr=NULL;
        printf("Nodos eliminados\n");
        }

}

void buscar(struct Dato *ptr, int num){
    struct Dato *ptraux=ptr;
    int pos = 1;
    int encontrado = 0;

    if(ptr == NULL){
        printf("No hay datos en la lista\n");
    }

    while(ptraux != NULL){
        if(ptraux->d == num){
            printf("Dato encontrado en la posicion %d\n", pos);
            encontrado = 1;
            break;
        }
        ptraux = ptraux->ptrSig;
        pos++;
    }

    if(!encontrado){
        printf("Dato no encontrado\n");
    }
}

void contar(struct Dato *ptr){
    struct Dato *ptraux;
    int cont=0;
    if(ptr==NULL)
        printf("No hay datos guardados\n");

    //cuando hay mas de un nodo
    ptraux=ptr;

    while(ptraux != NULL){
        cont ++;
        ptraux = ptraux->ptrSig;
    }

    printf("La cantidad de nodos son: %d", cont);
}/*

void ordenar (struct Dato *ptr){
    if(ptr==) 
    struct Dato *ptrAux;
     struct Dato *ptrtemp;
     struct Dato *ptrant;

     ptrAux=ptr;
     for (;ptrAux-> ptrSig!=NULL;){
        if(ptrAux->d >(ptrAux->ptrSig)->d){
            ptrAux=ptrtemp;
            ptrAux=ptrAux->ptrSig;
            ptrtemp->ptrSig=ptrAux->ptrSig;
            ptrAux->ptrSig=ptrtemp;
            ptrant->ptrSig=ptrAux;   
        }
        ptrant=ptrAux;
        ptrAux=ptrAux->ptrSig;
     }
     ptrAux=ptr;
     while(ptrAux!=NULL){
        printf("%d",ptrAux->d);
        ptrAux=ptrAux->ptrSig;
     }

}*/

void remplazar(struct Dato *ptr, int num){
    struct Dato *ptraux=ptr;
    int pos = 1;
    int encontrado = 0;

    if(ptr == NULL){
        printf("No hay datos en la lista\n");
    }

    while(ptraux != NULL){
        if(ptraux->d == num){
            printf("Ingrese el nuevo dato: ");
            scanf("%d", &ptraux->d);
            break;
        }
        ptraux = ptraux->ptrSig;
        pos++;
    }

    if(!encontrado){
        printf("Dato no encontrado\n");
    }
}

int main(){
    struct Dato *ptr=NULL, *ptrTemp=NULL, *ptrAux=NULL;
    int opc,op2;
    int num=0;
    int rem=0;

    do{
        opc=menu(opc);
        switch(opc){
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
                do {
                    op2=funcionesmenu();
                    switch (op2){
                    
                            case 1: printf("Ingrese el valor a buscar: ");
                                    scanf("%d", &num);
                            case 2: buscar(ptr, num);
                                    break;
                            case 3: contar(ptr);
                                    break;
                            //case 4: ordenar(ptr);
                                    //break;
                            case 5: remplazar(ptr, rem);
                                    break;
                            default: printf("Opcion no encontrada");
                                    break;
                        }
                    }while(op2!=5);
                    break;
            case 3:
                    mostrar(&ptr);
                    break;
            case 4:
                    liberar(&ptr);
                    break;
            case 5: eliminar(&ptr);
                    break;
            default: printf("Opcion no encontrada");
        }
    }while(opc!=5);
    return 0;
}
            
