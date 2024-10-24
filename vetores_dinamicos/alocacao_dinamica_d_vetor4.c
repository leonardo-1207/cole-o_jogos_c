#include <stdio.h>
#include <stdlib.h>
#define MAX 1500

/*4) Faça um programa para armazenar em memoria um vetor de dados contendo 1500
valores do tipo int, usando a função de alocação dinâmica de memória CALLOC:
a) Atribua para cada elemento do vetor o valor do seu índice.
b) Exibir na tela os 10 primeiros e os 10 últimos elementos do vetor.*/

//eite :https://gabrielbueno072.github.io/rea-aed/exercicios/lista11.pdf

int main(){

    int i=0,primeiros=0,ultimos=MAX-10;
    int *vetor = (int *) calloc(MAX,sizeof(int));

    if(vetor==NULL){
        printf("ERRO AOA ALOCAR MEMORIA");
    }

    for(i=0;i<MAX;i++){
        vetor[i]=i;
    }

    printf("10 primeiros:");

    while(primeiros<10){
        printf("%4d",vetor[primeiros]);
        primeiros++;
    }

    printf("\n\n10 ultimos:");

      while(ultimos<MAX){
        printf("%7d",vetor[ultimos]);
       ultimos++;
    }

    free(vetor);

    return 0;
}