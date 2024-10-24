#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.*/
// tirado do site : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

int calcula_fatorial(int n){

    int resultado=0;

    if(n==0){

       resultado=1;
    }

    else{

        return resultado = n *calcula_fatorial(n-1);
    }

    return (float *)resultado;

}

int main(){

srand(time(NULL));

   int numero = rand() % 100;

   printf("numero:%d\n\n",numero);


   calcula_fatorial(numero);

   printf("fatorial de %d: %d",numero,calcula_fatorial(numero));

    return 0;
}