#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*5) Crie uma função recursiva que receba um número inteiro positivo N e calcule o
somatório dos números de 1 a N.*/

//eite : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

int calcula_d_1_ate_n(int n,int soma,int i){
    if(i>n){

        return soma;
    }

    else{

        soma+=i;

        return calcula_d_1_ate_n(n,soma,i+1);
    }
}

int main(){
    
    srand(time(NULL));

    int numero = 1+ rand() % 100;
    printf("soma do 1 ao %d : %d",numero,calcula_d_1_ate_n(numero,0,0));

    return 0;
}