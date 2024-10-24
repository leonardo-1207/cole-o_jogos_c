#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10

/*4) Faça uma função recursiva que permita somar os elementos de um vetor de
inteiros.*/
//site : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

void prenche_vetor(int *v){

    srand(time(NULL));

    for(int i=0;i<TAMANHO;i++){

       v[i]=rand()%100;

        printf("%4d",v[i]);
    }
}

void soma_vetor(int *v,int i){

   if(i==-1){

    return;
   }

   else{

    v[i]+=v[i];

    return soma_vetor(v,i-1);
   }
}

void imprime_vetor(int *v){
    for(int i=0;i<TAMANHO;i++){
        printf("%4d",v[i]);
    }
}

int main(){

    int *vetor=NULL;
    int i=TAMANHO;

    vetor = (int *) malloc(TAMANHO * sizeof(int));
    if(vetor==NULL){
        printf("erro ao alocar memoria;");
        return 0;
    }

    prenche_vetor(vetor);

    printf("\n\nagora de pois da soma.\n\n");

    soma_vetor(vetor,i);

    imprime_vetor(vetor);

    free(vetor);

    return 0;
}