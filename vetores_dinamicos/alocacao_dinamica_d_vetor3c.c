#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/*3. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros, ´
(b) Pec¸a para o usuario digitar os 5 n ´ umeros no espac¸o alocado, ´
(c) Mostre na tela os 5 numeros, ´
(d) Libere a memoria alocada. */

//site : https://programacaodescomplicada.files.wordpress.com/2013/01/clista-10-alocacao-dinamica.pdf

int main(){

    int *vetor = (int *) calloc(MAX,sizeof(int));
    int i=0;
    if(vetor==NULL){
        printf("erro ao alocar memoria!!");
    }

    printf("digite os numeros para o vetor:");

    for(i = 0;i<MAX;i++){
        scanf("%d",&vetor[i]);
    }

    for(i = 0;i<MAX;i++){
        printf("%4d",vetor[i]);
    }

    free(vetor);

    return 0;
}