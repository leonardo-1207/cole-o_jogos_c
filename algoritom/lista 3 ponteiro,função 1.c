/*1. Faça um programa com uma função que recebe, por parâmetro, 2
vetores de 10 elementos inteiros e que calcula e retorna, também
por parâmetro, o vetor união dos dois primeiros.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencreV3(int v1[],int v2[],int v3[],int t){
    for(int i=0;i<t;i++){
        v3[i]=v1[i]+v2[i];
    }
}



int main(){

    int v[10],v2[10],v3[10];
    int i=0;
    srand(time(NULL));

    for(i=0;i<10;i++){
        v[i]= 1 + rand()%50;
        v2[i]= 1 + rand()%50;

        printf("%4d",v[i]);

    }
    printf("\n\n");
    for(i=0;i<10;i++){
        printf("%4d",v2[i]);

    }
    
    printf("\n\n");
   
    preencreV3(v,v2,v3,10);
    for(i=0;i<10;i++){
        printf("%4d",v3[i]);
    }


    return 0;
}