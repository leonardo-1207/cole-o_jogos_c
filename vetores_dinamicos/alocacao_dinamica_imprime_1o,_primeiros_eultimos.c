#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*2) Faça um programa que leia do usuário o tamanho de um vetor (inteiros) a ser lido e faça
a sua alocação dinâmica de memória. Depois, leia do usuário seus valores e imprima o
vetor lido e mostre quantos dos números são pares e quantos são ımpares.*/

//site : https://gabrielbueno072.github.io/rea-aed/exercicios/lista11.pdf


int main(){

    int tamanho=0;
    int *vetor = NULL;
    int par=0,impar=0,i;

    srand(time(NULL));

    printf("digite o tamanho d0 vetor:");
    scanf("%d",&tamanho);

    vetor= (int *)calloc(tamanho,sizeof(int));

    if(vetor==NULL){
        printf("ERRO AO ALOCAR MEMORIA!!!");
    }


    for(i=0;i<tamanho;i++){
        vetor[i]=rand()%100;
    }


    for(i=0;i<tamanho;i++){
        if(vetor[i]%2==0){
            par++;
        }
        else{
            impar++;
        }
        printf("%4d",vetor[i]);
    }
    printf("\n\n o vetor contem %d pares e %d impares.",par,impar);

 
    
    //o que o enunciado pede.
   /* printf("prencha o vetor:");
    for(int i=0;i<tamanho;i++){
        sanf("%d",&vetor[i]);
        if(vetor[i]%2==0){
            par++;
        }
        else{
            impar++;
        }
        printf("%4d",v[i]);
    }
    printf("\n\n o vetor contem %d pares e %d impares.",par,impar);*/

   

    free(vetor);
    return 0;
}