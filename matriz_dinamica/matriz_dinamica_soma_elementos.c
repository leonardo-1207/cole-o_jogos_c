#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 5
#define COLUNA 5

/*faca um amatriz 5x5 e some todos os seus elementos, imprime a matriz e a soma.*/

int main (){

    int **matriz = malloc(LINHA * sizeof(int *));
    int linhas,colunas,soma=0;

    srand(time(NULL));


    for(int i =0;i<COLUNA;i++){
        matriz[i] = malloc(COLUNA * sizeof(int));
    }

    for(linhas=0;linhas<LINHA;linhas++){
        for(colunas=0;colunas<COLUNA;colunas++){
            matriz[linhas][colunas] = 1 + rand() %100;
            soma+=matriz[linhas][colunas];

            printf("%4d",matriz[linhas][colunas]);
        }
        printf("\n");
    }

    printf("\n\na soma de tosod os elementos da matriz eh = %d.\n",soma);

    for(int i=0;i<COLUNA;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;

}