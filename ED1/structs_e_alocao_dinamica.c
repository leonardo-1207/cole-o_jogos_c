#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[100];
    char cpf[11];
    char rg[20];
    float peso;
    float altura;
}Pessoa;  

int main(){

    Pessoa *estudantes = (Pessoa *) malloc(sizeof(Pessoa) * 10);
   
    for(int i = 0; i < 10; i++){

        strcpy(estudantes[i].nome,"liza");
        strcpy(estudantes[i].cpf,"12234344374");
        strcpy(estudantes[i].rg,"1324578675");
        estudantes[i].peso = 60.75;
        estudantes[i].altura = 1.84;

        printf("nome: %s\ncpf: %s\nrg: %s\npeso: %.2f\naltura: %.2f\n\n",estudantes[i].nome,estudantes[i].cpf,estudantes[i].rg,estudantes[i].peso,estudantes[i].altura);
    }

    free(estudantes);

    
    return 0;
}