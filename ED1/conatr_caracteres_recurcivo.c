#include <stdio.h>
#include <stdlib.h>
//4. Contar os dígitos de um determinado número

int conta_digitos(int numero){

    if(numero < 10 && numero >= 0){
        return 1;
    }

    if(numero < 0){
        return conta_digitos(-numero);
    }

    return 1 + conta_digitos(numero/10);
}
   //co  ajuda do gpt
int main(){

    int numero = 0;

    printf("digite um numero:");
    scanf("%d",&numero);

    printf("\n\no numero contem %d digitos\n",conta_digitos(numero));

    return 0;
 
}