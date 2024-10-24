#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//8. Crie uma função em linguagem C chamado Dado() que retorna, através de sorteio, um número de 1 até 6.
//retirado de : https://www.cprogressivo.net/2013/03/Exercicios-sobre-funcoes-em-linguagem-de-programacao-C.html

int joga_dado_d_6_faces(int d){
    
    srand(time(NULL));

    d = 1 + rand() % 6;

    return d;
}

int main(){

    int dado=0;

     dado = joga_dado_d_6_faces(dado);

    printf("face do dado: %d",dado);

    return 0;
}