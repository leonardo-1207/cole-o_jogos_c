#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int valor;

    struct NO *proximo;
}no;

void libera_list(no *cabeca){
    no *atual = cabeca -> proximo;

    no *libera;

    while(atual != NULL){
        libera = atual;

        atual = atual -> proximo;
        
        free(libera);
    }
    printf("\n\nmemoria liberada com susseco");
}

void inceri_fii(no *cabeca,int Valor){
    no *novo = (no *) malloc(sizeof(no));
    
    novo -> proximo = NULL;

    novo -> valor = Valor;

    if(novo == NULL){
        printf("\nerro ao alocsr o no!!:\n");

        libera_list(cabeca);
    }

    no *atual = cabeca;

    while(atual -> proximo != NULL){
        atual = atual -> proximo;
    }

    atual -> proximo = novo;
}

void inprime_lista(no *cabeca){
    no *atual = cabeca ->proximo;

    int i=0;

    while(atual != NULL){
        printf("incdice %d, valor do no:%d\n",i+1,atual -> valor);

        atual = atual -> proximo;
        
        i++;
    }
}

int main(){
    no cabeca;

    cabeca.proximo = NULL;

    inceri_fii(&cabeca,12);

    inceri_fii(&cabeca,44);

    inceri_fii(&cabeca,76);

    inceri_fii(&cabeca,81);

    inceri_fii(&cabeca,144);

    inprime_lista(&cabeca);
    
    libera_list(&cabeca);

    return 0;
}