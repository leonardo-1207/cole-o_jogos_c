#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int i, t, *vec;

    srand(time(NULL));

    printf("digite o tamanho desejado para o vetor:");
    scanf("%d",&t);

    vec=malloc(t*sizeof(int));

    if(vec){
        for(i=0;i<t;i++){
            *(vec+i) = 1 + rand() % 50;
        }

            for(i=0;i<t;i++){
                printf("%4d",*(vec+i));
            }
    }

    else{
        printf("erro!!");
    }

    free(vec);

    return 0;
    //tomei de como referencia o vedeo do canal"Programe seu futuro", link do video:https://youtu.be/Co8Uuzs34qM?si=dJJiIAfIc4LcngZh
    //motivo : não domineo muito bem alocação dinâmica.
}