#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

//aloque um vetor de 10 posicoens e depois realoque para 15.

int main(){

    int *vetor=(int *)calloc(MAX,sizeof(int));
    int i=0;

    srand(time(NULL));

    for(i=0;i<MAX;i++){
        vetor[i]=rand()%100;
        printf("%4d",vetor[i]);
    }

    printf("\n\n");
    vetor = realloc(vetor,15*sizeof(int));

    for(i=0;i<15;i++){
        if(i>=10){
            vetor[i]=0;
        }
        printf("%4d",vetor[i]);
    }

    free(vetor);

    return 0;
}