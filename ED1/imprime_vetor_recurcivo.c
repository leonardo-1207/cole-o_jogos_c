#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//3. Imprimir os elementos de um array (vetor)

void preeche_vetor(int *vec,int tamanho){
    
    srand(time(NULL));

    for(int i = 0; i < tamanho; i ++){

        vec[i] = rand()%101;
    }
}

int imprime_vetor(int *vec,int tamanho){

    if(tamanho >= 10){

        return 0;
    }

    printf("%4d",vec[tamanho]);

    return imprime_vetor(vec,tamanho+1);
}

int main(){

    int vec[10];

    preeche_vetor(vec,10);

    imprime_vetor(vec,0);

    return 0;
}