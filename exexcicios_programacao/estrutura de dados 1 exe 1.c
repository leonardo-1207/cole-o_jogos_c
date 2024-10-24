/*1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao. */
#include<stdio.h>

int main(){
	int num=10;
	float i=1.38;
	char letra='a';

	int *ptr_inteiro=&num;
	float *ptr_flot=&i;
	char *ptr_caracter=&letra;

	printf("valor incial de num = %d\n",num);
	printf("vlaor inciaç de i = %.2f\n",i);
	printf("caracter inicial  de letra = %c\n\n",letra);

	*ptr_inteiro = *ptr_inteiro + 1;

	*ptr_flot = *ptr_flot + 1.12;

	*ptr_caracter = 'p';

	printf("volores apos a troca de valores com ponteiros.\n\n");

	printf("valor de num apos a troca = %d\n",num);
	printf("valor de i apos a troca = %.2f\n",i);
	printf("caracter de letra apos atroca = %c\n",letra);

	ptr_inteiro=NULL;
	ptr_flot=NULL;
	ptr_caracter=NULL;

	return 0;
//exercicio tirado de: https://www.facom.ufu.br/~backes/wordpress/ListaC09.pdf
//motivo da ecolha do execicio: ponteiros é meio dificil, acho importante praticar.
}