#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*13) Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem decrescente.*/

//site : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

void imprime_numeros_d_0_a_n(int numero,int i){

    if(i>numero){
        return;
    }

    else{
        printf("%-4d",i);
        return imprime_numeros_d_0_a_n(numero,i+1);
    }
}

int main(){

    srand(time(NULL));

    int numero = rand() % 100;
    printf("numero sorteado: %d\n\nnumeros entre esntre ele.\n",numero);

    imprime_numeros_d_0_a_n(numero,0);

    return 0;
}