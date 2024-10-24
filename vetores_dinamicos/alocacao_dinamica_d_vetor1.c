#include <stdio.h>
#include <stdlib.h>

/*1. Fac¸a um programa que leia do usuario o tamanho de um vetor a ser lido, fac¸a a alocac¸ ´ ao˜
dinamica de mem ˆ oria, leia do usu ´ ario seus valores inteiros e imprima o vetor lido.*/

//site :https://programacaodescomplicada.files.wordpress.com/2013/01/clista-10-alocacao-dinamica.pdf
int main(){


    int tamanho=0;
    
    printf("digite o tamanho do vetor:");
    scanf("%d",&tamanho);

    int *vetor =(int *) malloc(tamanho*sizeof(int));

    if(vetor==NULL){
        printf("erro ao alocar memoria!!");
    }

    printf("agora preencha o vetor:");

    for(int i=0;i<tamanho;i++){
        scanf("%d",&vetor[i]);
    }

    printf("\n\n");
    for(int i=0;i<tamanho;i++){
      printf("%4d",vetor[i]);
    }


    free(vetor);

    return 0;
}