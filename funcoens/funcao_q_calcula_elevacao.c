#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*6) Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule kn
. Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
função.*/

//sita : https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

int elevacao_d_numeros(int numero,int elevacao){

    if(elevacao==0){
        return 1;
    }

    else{
        return numero* elevacao_d_numeros(numero,elevacao-1);
    }
}

int main(){
    
    int numero=0,elevacao=0;

    printf("digite o numero:");
    scanf("%d",&numero);
    
    printf("agora dgite o numero de que deja elevalo:");
    scanf("%d",&elevacao);

    //uma alternativa sem emcomodar o usuario.

   /*srand(time(NULL));
    numero=rand()%100;
    elevacao=rand()%100;*/ 

    printf("%d elevado a %d = %d",numero,elevacao,elevacao_d_numeros(numero,elevacao));

    return 0;
}