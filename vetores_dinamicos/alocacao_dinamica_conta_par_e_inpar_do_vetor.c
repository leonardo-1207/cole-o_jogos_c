#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

/*4. Fac¸a um programa que leia n inteiros (definidos pelo usuario) armazenando-os em uma ´
memoria alocada dinamicamente. Em seguida, mostre quantos dos n n ´ umeros s ´ ao pares ˜
e quantos sao˜ ´ımpares.*/

//site : https://programacaodescomplicada.files.wordpress.com/2013/01/clista-10-alocacao-dinamica.pdf

void conta_pares_e_inpares(int *v,int par,int impar){

    for(int i=0;i<MAX;i++){

        if(v[i]%2==0){

            par++;

        }

        else{

            impar++;

        }
    }

    printf(" numero de pares: %d\nnumero de impares: %d",par,impar);
}

int main(){

    int *vetor = (int *) calloc(MAX,sizeof(int));
    int i=0;

    printf("prencha o vetor:");

    for(i=0;i<MAX;i++){
        
        scanf("%d",&vetor[i]);

        /*srand(time(NULL));
          vetor[i]=rand()%100;*/
    }

    conta_pares_e_inpares(vetor,0,0);
    
    free(vetor);

    return 0;
}