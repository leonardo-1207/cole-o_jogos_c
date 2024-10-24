#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 4
#define COLUNA 4

/*3. Fac¸a um programa que preenche uma matriz 4 x 4 com o produto do valor da linha e da
coluna de cada elemento. Em seguida, imprima na tela a matriz.*/


int main(){

    int **matriz,linhas=0,colunas=0;

    matriz = malloc(LINHA * sizeof(int *));

    for(int i=0 ;i<5;i++){
        matriz[i] = malloc(COLUNA * sizeof(int));
    }


    for(linhas = 0 ; linhas < LINHA ; linhas++){
        for(colunas = 0 ; colunas < COLUNA ; colunas++){
            matriz[linhas][colunas] = linhas * colunas;
            printf("%4d",matriz[linhas][colunas]);
        }
        printf("\n");
    }


    for(int i=0;i<COLUNA;i++){
        free(matriz[i]);
    }

    free(matriz);


    return 0;
}