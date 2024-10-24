#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_L 5
#define NUM_C 5

/*5. Leia uma matriz 5 x 5. Leia tambem um valor ´ X. O programa devera fazer uma busca ´
desse valor na matriz e, ao final, escrever a localizac¸ao (linha e coluna) ou uma mensa- ˜
gem de “nao encontrado”.*/

int main(){

    int **matriz = malloc(NUM_L * sizeof(int *));
    int linha=0, coluna=0,numero=0,achou=0;

    srand(time(NULL));
    
    for(int i=0; i<NUM_C;i++){

        matriz[i] = malloc(NUM_C * sizeof(int));
    }

    for(linha=0;linha<NUM_L;linha++){

        for(coluna=0;coluna<NUM_C;coluna++){

            matriz[linha][coluna] = 1 + rand () %100;

            //printf("%4d",matriz[linha][coluna]);
        }
       // printf("\n");
    }


    printf("digite um valor para cer buscado no vetor:");
    scanf("%d",&numero);

    
    for(linha=0;linha<NUM_L;linha++){

        for(coluna=0;coluna<NUM_C;coluna++){

           if(numero==matriz[linha][coluna]){

            achou=1;

            printf("o numero foi emcntrado na linha %d e coluna %d.\n\n",linha,coluna);

            break;
           }
        }
    }

    if(achou == 0){

        printf("numero nao encontrado.\n\n");
    }
    
    for(linha=0;linha<NUM_L;linha++){

        for(coluna=0;coluna<NUM_C;coluna++){

           printf("%4d",matriz[linha][coluna]);
           
        }
        printf("\n");
    }

    for(int i=0;i<NUM_C;i++){

        free(matriz[i]);
    }

    free(matriz);

    return 0;
}