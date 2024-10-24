/*Dado um vetor de inteiros e o seu número de elementos, inverta a
posição dos elementos dentro do vetor usando ponteiros. Nesse
caso, você terá um ponteiro que começa “apontando” para o
primeiro elemento do vetor e avança em direção ao seu final e outro
ponteiro que começa “apontando” para o último elemento do vetor e
avança em direção ao seu início. OBS.: você já resolveu esse
problema anteriormente usando uma função recursiva, mas agora
deve resolvê-lo usando ponteiros e laço de repetição. */


#include <stdio.h>


int main(){

    int vet[4];
    int *ptr=NULL;
    int *ptr2=NULL;
    int i,aux;
    
    printf("preencha o vetro de 4 posisoens:\n");
    for(i=0;i<4;i++){
        scanf("%d",&vet[i]);
    }

    ptr=vet;
    ptr2=&vet[3];
    aux=*ptr;

    *ptr=*ptr2;
    *ptr2=aux;

    ptr=&vet[1];
    ptr2=&vet[2];
    aux=*ptr;

    *ptr=*ptr2;
    *ptr2=aux;

    for(i=0;i<4;i++){
        printf("%4d",vet[i]);
    }

    return 0;
}