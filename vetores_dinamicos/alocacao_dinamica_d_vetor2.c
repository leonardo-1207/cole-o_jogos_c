#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*2. Fac¸a um programa que leia uma quantidade qualquer de numeros armazenando-os na ´
memoria, pare a leitura quando o usu ´ ario entrar um n ´ umero negativo e imprima o vetor ´
lido.*/

//site : https://programacaodescomplicada.files.wordpress.com/2013/01/clista-10-alocacao-dinamica.pdf

int main(){

    int *vetor = (int *) calloc(MAX, sizeof(int));
    int i=0;
    if(vetor==NULL){
        printf("erro ao alocra memoria!!!");
    }
    printf("preencha o vetor.");
    for( i=0;i<MAX;i++){
        scanf("%d",&vetor[i]);
        if(vetor[i]<0){
            break;
        }
    }

    for(i=0;i<MAX;i++){
        printf("%4d",vetor[i]);
    }
    
    free(vetor);

    return 0;
}