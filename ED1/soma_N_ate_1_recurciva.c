#include <stdio.h>
//1. Calcular a soma dos números naturais de 1 até n

int somaNreais(int n){

    if(n == 1){

        return 1;

    }

    return n + somaNreais(n -1);
}

int main(){

    int n = 0;
    printf("\nCALCULS DE 1 ATE N.\n\ndigite o numero de N : ");
    scanf("%d",&n);
    printf("\n%d\n",somaNreais(n));

    return 0;
}   