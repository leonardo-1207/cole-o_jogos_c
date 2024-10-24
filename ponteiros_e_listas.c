#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int *v,int tamanho){

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){

        v[i] = rand()%101;
        
        printf("%-4d",v[i]);
    }
}

void maiorEmenor(int *v,int tamanho,int *maior,int *menor){

    *maior = v[0];
    *menor = v[0];

    for(int i = 0; i < tamanho; i++){

        if(v[i] > *maior){

            *maior = v[i];
        }

        if(v[i] < *menor){

            *menor = v[i];
        }
    }
}

int main(){
  
  int vec[5];
  int maior = 0 ,menor = 0;

  preencheVetor(vec,5);

  maiorEmenor(vec,5,&maior,&menor);

  printf("\n\n%d %d",maior,menor);

    return 0;
}