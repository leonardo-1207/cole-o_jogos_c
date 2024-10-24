/*4. Leia uma matriz 4 x 4, imprima a matriz e retorne a localizac¸ao (linha e a coluna) do ˜
maior valor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_L 4
#define N_C 4

int main(){

    int matriz[N_L][N_C];

    int l=0,c=0,i=0,maior=0;

    srand(time(NULL));

    for(l=0;l<N_L;l++){
        for(c=0;c<N_C;c++){
           
            matriz[l][c] = 1 + rand() %100;
        }
    }
    
    for(l=0;l<N_L;l++){

        printf("\n");

        for(c=0;c<N_C;c++){

            printf("%4d",matriz[l][c]);
        }
    }

    for(l=0;l<N_L;l++){
        for(c=0;c<N_C;c++){

            i=matriz[l][c];

            if(i>maior){

                maior =i;

                break;
            }
        }
    }

    printf("\n\no maior elemento encontra-se na linha %d  e na coluna %d\no maior elemento eh: %d",l,c+1,maior);

    return 0;
    //retirado de: https: //www.facom.ufu.br/~backes/gci007/ListaC04.pdf
    // motivo da escolha: praticar matriz.
}