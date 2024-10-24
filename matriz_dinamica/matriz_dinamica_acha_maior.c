#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 4
#define COLUNA 4

/*4. Leia uma matriz 4 x 4, imprima a matriz e retorne a localizac¸ao (linha e a coluna) do ˜
maior valor.*/

int main(){

    int **matriz;
    int linha=0,coluna=0,maior=0;

    srand(time(NULL));

    matriz = malloc(LINHA * sizeof(int *));

    for(int i=0;i<COLUNA;i++){

        matriz[i] = malloc(COLUNA * sizeof(int));
    }

    for(linha=0;linha<LINHA;linha++){

        for(coluna=0;coluna<COLUNA;coluna++){

            matriz[linha][coluna] = 1 + rand()% 100;

            if(matriz[linha][coluna]>maior){

                maior = matriz[linha][coluna];
            }
        }
    }
    
    for(linha=0;linha<LINHA;linha++){

        for(coluna=0;coluna<COLUNA;coluna++){

           if(matriz[linha][coluna]==maior){

            break;
           }
        }
    }

    printf("o maior numero se necontra na linha %d na coluna %d\n\n o numero :%d\n\n",linha,coluna,maior);

    for(linha=0;linha<LINHA;linha++){

        for(coluna=0;coluna<COLUNA;coluna++){

            printf("%4d",matriz[linha][coluna]);
        }

        printf("\n");
    }

    for(int i=0; i<COLUNA;i++){

        free(matriz[i]);
    }

    free(matriz);

    return 0;
}