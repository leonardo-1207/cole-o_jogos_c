#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*2) Faça uma função que receba dois números inteiros positivos por parâmetro e
retorne a soma de todos os números existentes entre eles.*/
//retirado de : https://www.feg.unesp.br/Home/PaginasPessoais/profmarlondasilva/lista6.pdf

int soma_diferenca_d_numeros(int n, int n2){
    int i=0,soma=0;

    for(i=n+1;i<n2;i++){

        soma+=i;
    }
    return soma;
}

int main(){

    int numero=0,numero2=0,diferenca=0;

    srand(time(NULL));
    numero = rand() %100;
    numero2 = rand() %100;

    printf("primeriro numero: %d\n\nsegundo numero: %d\n\n",numero,numero2);

    diferenca = soma_diferenca_d_numeros(numero,numero2);

    printf("soma da diferenca entre estes dois numeros: %d",diferenca);

}