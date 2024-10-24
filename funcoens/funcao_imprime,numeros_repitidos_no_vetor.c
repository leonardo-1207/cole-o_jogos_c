#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6

/*17. 8. Crie um programa que le 6 valores inteiros e, em seguida, mostre na tela os valores lidos ˆ
na ordem inversa.*/

// site: https://www.facom.ufu.br/~backes/gci007/ListaC04.pdf

void preenche_vetor(int *v,int i){

   if(i>=6){
    return;
   }

   else{

    v[i]=rand()%100;
    printf("%4d",v[i]);
    return preenche_vetor(v,i+1);
   }
}

void imprime_vetor(int *v,int i){
    if(i<0){
        return;
    }

    else{
        printf("%4d",v[i]);
        return imprime_vetor(v,i-1);
    }
}

int main(){

    int *vetor=(int *)malloc(MAX * sizeof(int));
    srand(time(NULL));

    if(vetor==NULL){
        printf("erro ao alocar memoria !!!");
    }

    preenche_vetor(vetor,0);

    printf("\n\n");

    imprime_vetor(vetor,5);


    free(vetor);

    return 0;
}