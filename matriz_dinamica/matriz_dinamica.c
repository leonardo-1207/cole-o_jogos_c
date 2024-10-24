#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHAS 4
#define COLUNAS 4

/*1. Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.*/


int main(){

    int **matriz,linhas=0,colunas=0;
    int maiorQ10=0;

    srand(time(NULL));

    matriz = malloc(LINHAS * sizeof(int *));

    for(int i=0 ;i<COLUNAS;i++){

        matriz[i] = malloc(COLUNAS * sizeof(int));
    }

    for(linhas = 0 ; linhas < LINHAS ; linhas++){

        for(colunas = 0 ; colunas < COLUNAS ;colunas++){

            matriz[linhas][colunas] = 1 + rand() %100;

            if(matriz[linhas][colunas]>10){

                maiorQ10++;
            }

            printf("%4d",matriz[linhas][colunas]);
        }
        printf("\n");
    }

    printf("\nesta matriz possue %d numeros maior que 10",maiorQ10);

    for(int i = 0 ; i < COLUNAS ; i++){

        free(matriz[i]);
    }

    free(matriz);

    return 0;
}