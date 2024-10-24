#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*14) Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem crescente.
*/

// site: https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

void imprime_pares_d_0_a_n(int numero,int i){

    if(i>numero){
        return ;
    }

    else{

        if(i%2==0){
            printf("%4d",i);
        }
        
        return imprime_pares_d_0_a_n(numero,i+1);
    }
}

int main(){

    srand(time(NULL));

    int numero=rand()%100;
    
    if(numero%2==1){
        //o enunciado exige um par
        while(numero%2==1){
            numero=rand()%100;
        }
    }

    printf("numero sorteado: %d\n\nnumeros pares emtre ele:",numero);

    imprime_pares_d_0_a_n(numero,0);

    return 0;
}