#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arq;

    arq=fopen("ola.txt", "w");
    if(arq==NULL){
        printf("erreo ao abrir o arquivo");
    }

    fprintf(arq,"cu.");
    fprintf(arq,"\n19 nao eh 20.");

    fclose(arq);
    printf("deu certo.");

    return 0;
}