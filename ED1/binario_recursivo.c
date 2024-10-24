#include <stdio.h>
//8. Converter um número decimal em binário

void conversor_binario(int numero){

    if(numero == 0){

        return;
    }
   
    conversor_binario(numero / 2);

    printf("%d", numero % 2);
}

int main(){

    int numero;

    printf("digite um numero: ");
    
    scanf("%d",&numero);

    if(numero == 0){
    
       printf("0\n");
    }

    conversor_binario(numero);

    return 0;
}