#include <stdio.h>
#include <stdlib.h>

//5. Encontrar a soma dos dígitos de um número

int encontra_soma(int numero){

    if(numero < 0){
        numero = -numero;
    }

    if(numero == 0){
        return 0;
    }

    return (numero % 10) + encontra_soma(numero /10);
}
  //com ajuda do gpt
int main(){

   int numero = 0;

   printf("digite um numero:");
   scanf("%d",&numero);

   printf("%d",encontra_soma(numero));

    return 0;
  
}