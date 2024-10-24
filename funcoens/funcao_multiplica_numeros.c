#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*11) A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros.*/

// site: https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf

int multiplica_n_x_n(int numero, int numero2, int soma){

    if(numero2 == 0){
        return soma;
    }

    else{
        soma = soma + numero;

        return multiplica_n_x_n(numero,numero2-1,soma);
    }
}

int main(){

    srand(time(NULL));

    int numero1 = 5 , numero2 = 5;

    printf("%d * %d = %d",numero1,numero2, multiplica_n_x_n(numero1,numero2,0));

    return 0;
}