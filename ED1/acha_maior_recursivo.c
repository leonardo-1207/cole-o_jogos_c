#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//6 Obter o maior elemento de um array

void preenche_vetor(int *vec,int tamanho){

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){

        vec[i] = rand()%101;
        
        printf("%4d",vec[i]);
    }
}

int acha_maior(int *vec,int tamanho,int maior){

    if(tamanho > 10){

        return maior;
    }

    if(vec[tamanho] > maior){

        maior = vec[tamanho];
    }

    return acha_maior(vec,tamanho+1,maior);
}

int main(){

    int vec[10];

    int maior = 0;

    preenche_vetor(vec,10);

    maior = vec[0];

    printf("\n\neste eh o maior elemento do vetor : %d",acha_maior(vec,0,maior));

    return 0;
}