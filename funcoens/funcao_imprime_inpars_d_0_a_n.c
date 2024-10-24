#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*15) Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem decrescente.*/

// site: https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

void imprime_inpares(int numero,int i){

    if(i>numero){
        return;
    }

    else{
        if(i%2==1){
            printf("%4d",i);
        }
        return imprime_inpares(numero,i+1);
    }
}

int main(){

    srand(time(NULL));

    int numero=rand()%100;

    if(numero%2==0){
        
        while(numero%2==0){
            numero=rand()%100;
        }
    }
    
    printf("numero inpra sorteado: %d\n\nnumeros inpares entre ele:",numero);

    imprime_inpares(numero,0);

    return 0;
}