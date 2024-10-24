#include <stdio.h>
#include <stdlib.h>

typedef struct NO{

    int valor;
    int linhas_posicao;
    int coluna_posicao;
    struct NO *proximo;
}No;

void novo_no(No **cabeca, int elemento_nao_nulo, int linha, int coluna){

    No *temp, *r;
    temp = *cabeca;

    if(temp == NULL){

        temp = (No *) malloc(sizeof(No));
        temp -> valor = elemento_nao_nulo;
        temp -> linhas_posicao = linha;
        temp -> coluna_posicao = coluna;
        temp -> proximo = NULL;
        *cabeca = temp;
    }

    else{

        while(temp -> proximo != NULL){

            temp = temp -> proximo;
        }

        r = (No *) malloc(sizeof(No));
        r -> valor = elemento_nao_nulo;
        r -> linhas_posicao = linha;
        r -> coluna_posicao = coluna;
        r -> proximo = NULL;
        temp -> proximo = r;
    }
}

void printf_LIL(No *cabeca){

}

int main(int argc,char **argv[]){

    if(argc<2){

        printf("imforme o nome do dataset.");
        return 1;
    }

    No *cabeca = NULL;

    return 0;
}