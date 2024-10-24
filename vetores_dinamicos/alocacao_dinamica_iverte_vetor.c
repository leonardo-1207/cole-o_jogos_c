#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

//inverta um vetor dinamico

int main(){

    int *vetor=malloc(MAX*sizeof(int));
    int inicio=0,fim=MAX-1,i,guarda;

    srand(time(NULL));


    for(i=0;i<MAX;i++){
        vetor[i]=rand()%100;
        printf("%4d",vetor[i]);
    }

    printf("\n\nvetor in vertido\n\n");

    
    for(i=0;i<MAX;i++){

        guarda=vetor[inicio];

        vetor[inicio]=vetor[fim];

        vetor[fim]=guarda;
        inicio++;
        fim--;
        if(inicio >=fim){
            break;
        }
        
    }

    for ( i = 0; i < MAX; i++){
        printf("%4d",vetor[i]);    
    }
    

    free(vetor);
    
    return 0;
}