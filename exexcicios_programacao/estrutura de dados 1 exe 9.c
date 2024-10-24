/*3. Fac¸a um programa que preenche uma matriz 4 x 4 com o produto do valor da linha e da
coluna de cada elemento. Em seguida, imprima na tela a matriz*/

#include <stdio.h>
#define N_L 3
#define N_C 3

int main(){
    int l=0,c=0;
    int matriz[l][c];

    for(l=0;l<N_L;l++){
        
        printf("\n");

        for(c=0;c<N_C;c++){
            
            matriz[l][c]=l*c;
            
            printf("%4d",matriz[l][c]);
        }
    }

return 0;
//retirado de :https://www.facom.ufu.br/~backes/gci007/ListaC04.pdf
//motivo : praticar matiz.
}