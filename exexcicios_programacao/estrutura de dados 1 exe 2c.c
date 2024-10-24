/*2. Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o.*/
#include <stdio.h>

int main (){

    int n=10,n2=45;

    int *ptr_n1 = &n;
    int *ptr_n2 = &n2;

    printf("endereco de n = %d\n",&n);
    printf("endereco de n2 = %d\n\n",&n2);

    if(ptr_n1>ptr_n2){
        printf("ptr_n1 tem o maior numero de enderco %d",ptr_n1);
    }
    else {
        printf("ptr_n2 tem o maior numero de enderco %d",ptr_n2);
    }

    ptr_n1=NULL;
    ptr_n2=NULL;

    return 0;
    //exercicio tirado de: https://www.facom.ufu.br/~backes/wordpress/ListaC09.pdf
    //motivo da ecolha do execicio: ponteiros é meio dificil, acho importante praticar.
}