/*4. Fac¸a um programa que leia 2 valores inteiros e chame uma func¸ao que receba estas ˜
2 variaveis e troque o seu conte ´ udo, ou seja, esta func¸ ´ ao˜ e chamada passando duas ´
variaveis A e B por exemplo e, ap ´ os a execuc¸ ´ ao da func¸ ˜ ao, A conter ˜ a o valor de B e B ´
tera o valor de A.*/
#include <stdio.h>

void troca_valor(int *n1,int *n2){
    int guarda=0;
    guarda=*n1;

    *n1=*n2;

    *n2=guarda;
}


int main (){

    int a=5,b=8;

    printf("valor incial de a = %d\nvalor inicial de b = %d\n\n",a,b);

    printf("vaolores trocados.\n\n");

    troca_valor(&a,&b);
    printf("valor de a = %d\n valor de b = %d\n",a,b);
    
    return 0;

     //exercicio tirado de: https://www.facom.ufu.br/~backes/wordpress/ListaC09.pdf
    //motivo da ecolha do execicio: ponteiros é meio dificil, acho importante praticar.
}