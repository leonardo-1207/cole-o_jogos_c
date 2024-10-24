#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int vol;
   struct nodo *proximo;
    
}nodo;

//insere um novo elemento na lista 
nodo* insere(nodo *p, int n){

    nodo * aux;

    aux = (nodo*) malloc(sizeof(nodo));

    if(!aux){
        return NULL;
    }

    aux-> vol = n;
    aux -> proximo = p;

    return aux;
}

//insere no final da lista;
/*nodo * insere_fim(nodo *p, int n){

    nodo * aux = p;

    nodo * aux2 = (nodo*) malloc(sizeof(nodo));
    if(!aux2){
        return NULL;
    }

    aux2 -> vol = n;
    aux2 -> proximo = NULL;
    if(!aux){
        return aux;
    }

    while(aux-> proximo != NULL)
    aux = aux -> proximo;
    
    aux -> proximo = aux2;

    return p; 
}*/

void imprime_lista(nodo *p){
    nodo *atual = p;

    while(atual != NULL){
        printf("%4d", atual->vol);
        atual = atual -> proximo;
    }

    printf("    NULL\n");
}

int main(){
    nodo *plista;

    plista = NULL;

    plista = insere(plista, 33);
    plista = insere(plista, 3);
    plista = insere(plista, 36);
    plista = insere(plista, 73);
    plista = insere(plista, 90);

    imprime_lista(plista);

    return 0;
}