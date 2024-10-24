#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10

/*22. Fac¸a um programa que leia dois vetores de 10 posic¸oes e calcule outro vetor contendo, ˜
nas posic¸oes pares os valores do primeiro e nas posic¸ ˜ oes impares os valores do se- ˜
gundo.*/

//retirado de: https://www.facom.ufu.br/~backes/gci007/ListaC04.pdf

void preeche_vetor(int *vetor){

    for(int i=0;i<TAMANHO;i++){

        vetor[i]=rand() %100;
        
        printf("%4d",vetor[i]);
    }
}

void preenche_terceiro_vetor(int *VETOR1, int *VETOR2, int *VETOR3){

    for(int i=0;i<TAMANHO;i++){
        if(i%2==0){

            VETOR3[i]=VETOR1[i];
        }
        else{

            VETOR3[i]=VETOR2[i];
        }
        
        printf("%4d",VETOR3[i]);
    }
}

int main(){

    int vetor1[TAMANHO],vetor2[TAMANHO],vetor3[TAMANHO];

    srand(time(NULL));

    preeche_vetor(vetor1);

    printf("\n\n");

    preeche_vetor(vetor2);

    printf("\n\n");

    preenche_terceiro_vetor(vetor1,vetor2,vetor3);

    return 0;
}