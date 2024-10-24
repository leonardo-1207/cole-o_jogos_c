#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crie um pequeno banco de dados com um vetor estático de ponteiros para três
//structs do tipo GAME contendo informações sobre jogos do console Atari 2600.
//A struct GAME deverá possuir os campos abaixo:
//a) Nome do jogo (string)
//b) Gênero (string)
//c) Fabricante (string)
//d) Ano (int)
//Utilize o comando malloc para criar as structs na memória e armazene os dados dos
//jogos. Permita que o usuário consulte o jogo pelo nome. Ao fim da consulta, faça free nos
//endereços das structs para liberar a memória. Pesquise jogos reais para inserir os dados.

typedef struct{
    char nome_jogo[100];
    char genero[100];
    char fabricante[100];
    int ano;
}GAME;

void preenche(GAME **vetor){

    //jogos pesquisados no cahtgpt.
    strcpy(vetor[0]->nome_jogo,"space invaders");
    strcpy(vetor[0]->genero,"shoot'em up");
    strcpy(vetor[0]->fabricante,"Atari, Inc");
    vetor[0]->ano = 1980;

    strcpy(vetor[1]->nome_jogo,"pac-man");
    strcpy(vetor[1]->genero,"maze");
    strcpy(vetor[1]->fabricante,"Atari, Inc");
    vetor[1]->ano = 1982;

    strcpy(vetor[2]->nome_jogo,"frogger");
    strcpy(vetor[2]->genero,"action / maze");
    strcpy(vetor[2]->fabricante,"Parker Brothers");
    vetor[2]->ano = 1982; 
}

void imprime(GAME **vetor,int i){
    printf("%s\n",vetor[i]->nome_jogo);
    printf("genero: %s\n",vetor[i]->genero);
    printf("feito por %s\n",vetor[i]->fabricante);
    printf("ano de lancamento: %d\n\n",vetor[i]->ano);
}

void libera(GAME **vetor,int t){
    for(int i = 0; i < t; i++){
        free(vetor[i]);
    }
}

int main(){

    GAME *banco_d_dados[3];
    char nome_do_jogo[100];

    for(int i = 0; i < 3; i++){
        banco_d_dados[i] = (GAME *) malloc(sizeof(GAME));
    }

    preenche(banco_d_dados);

    printf("\njogos disponiveis: space invaders, pac-man, frogger,\n");
    printf("\nqual jogo deseja pesquizar? ");
    scanf("%[^\n]",nome_do_jogo);
    printf("\n");

    for(int i = 0; i<3; i++){

        if(strcmp(nome_do_jogo, banco_d_dados[i]->nome_jogo) == 0){
            imprime(banco_d_dados,i);
        }
    }
   
    libera(banco_d_dados,3);
    
    return 0;
}