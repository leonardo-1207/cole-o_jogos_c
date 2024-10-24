#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/*7) Crie um programa em C que receba um vetor de números reais com 100 elementos.
Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor*/

//site : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

void invete_vetor(float *v,int inicio,int fim){
   
    float grada=v[inicio];

    if(inicio>=fim){
        return ;
    }

    else{
        v[inicio]=v[fim];
        v[fim]=grada;
        return invete_vetor(v,inicio+1,fim-1);

    }
}

int main(){

    float *vetor = (float *) malloc(MAX*sizeof(float));
    if(vetor==NULL){
        printf("erro ao alocar memoria");
        return 0;
    }

    srand(time(NULL));

    for(int i=0;i<MAX;i++){
        vetor[i] = rand ()% 100;
        printf("%4.0f",vetor[i]);
    }

    invete_vetor(vetor,-1,100);

    printf("\n\nvetor invetido\n\n");


    for(int i=0;i<MAX;i++){
        printf("%4.0f",vetor[i]);
    }


    free(vetor);

    return 0;
}