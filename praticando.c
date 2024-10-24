#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMERO_D_PALAVRAS 3

char *PALAVRAS[]={"paraquedas",
                  "cafe",
                  "carro"};

void copia_palavra(char *palavra,char *palavra2,int c){
    
    int i=0;

    for(i = 0 ;PALAVRAS[c][i] != '\0'; i++){

        palavra[i] = PALAVRAS[c][i];
    }

    palavra[i] = '\0';

    for(i = 0 ;palavra[i] != '\0'; i++){

     palavra2[i]='_';
    }

    palavra2[i]='\0';
}

void dica(int celetor){

    switch(celetor){

        case 0:
        printf("DICA: Usado para nao morrer enqaunto cai.\n");
        break;
        
        case 1:
        printf("DICA: Leo adora tomar.\n");
        break;

        case 2:
        printf("DICA: VRUUMMM  VRUUMMM.\n");
        break;
    }
}

int main(){

    srand(time(NULL));

    int celetor = rand()% NUMERO_D_PALAVRAS;
    char letra;
    char *palavra = (char *) malloc(strlen(PALAVRAS[celetor])+1);
    char *palavra_digitada = (char *)  malloc(strlen(palavra)+1);

    copia_palavra(palavra,palavra_digitada,celetor);

    printf("ACERTE  A PALAVRA.\n");
    dica(celetor);

    while(strcmp(palavra,palavra_digitada)!=0){

        scanf(" %c",&letra);

        if(letra < 'a'|| letra > 'z'){

            printf("caracter invalido tente novamente.");
            continue;
        }

        for(int i = 0 ;palavra[i] != '\0'; i++){

            if(letra==palavra_digitada[i]){

                printf("letra ja etsa pesente, tente outa.\n");
            }
            
            else{

                if(letra==palavra[i])
                palavra_digitada[i]=letra;
            }
        }
        puts(palavra_digitada);
    }

    if(strcmp(palavra,palavra_digitada)==0){
        printf("\nPARABENS VCOCE ARCETOU A PALAVRA!!!!\n");
    }
    setbuf(stdin,NULL);

   
    free(palavra);
    free(palavra_digitada);
    printf("precine nter apara finalizar.");
    getchar();   

    return 0;
}