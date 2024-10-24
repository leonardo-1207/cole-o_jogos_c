#include <stdio.h>
#include <stdlib.h>

/*1. Crie uma struct para representar um personagem de jogo com atributos
como nome, nível e pontos de vida. Implemente uma função para alocar
dinamicamente um vetor de personagens. Permita ao usuário adicionar
novos personagens ao vetor.*/

typedef struct{
    char nome[100];
    int nivel;
    int vida;
}Personagem;

void aloc_e_cria(Personagem **p,int t){
    
    *p = (Personagem *) malloc(sizeof(Personagem) * t);


    for(int i = 0; i < t; i++){
        printf("digite o nome:");
        scanf("%s", (*p)[i].nome);

        printf("nivel e vida:");
        scanf("%d %d", &(*p)[i].nivel, &(*p)[i].vida);
    }
}

void aloc_mais(Personagem **p,int t,int *novot){

    *p = (Personagem *) realloc(*p,(*novot + t) * sizeof(Personagem));

    for(int i = *novot; i < *novot + t; i++){
        printf("digite o nome:");
        scanf("%s", (*p)[i].nome);

       printf("nivel e vida:");
       scanf("%d %d", &(*p)[i].nivel, &(*p)[i].vida);
    }
    *novot += t;
}

int main(){

    Personagem *p;
    int t,novot;
    char acao = 's';
    printf("quantos personagems: deseja criar?");
    scanf("%d", &t);

    aloc_e_cria(&p,t);

   

    printf(" de seja criar mais personagems?");
    scanf(" %c",&acao);

    while(acao == 's'){

        printf("quantos?");
        scanf("%d",&novot);

        aloc_mais(&p,t,&novot);

        printf(" de seja criar mais personagems?");
        scanf(" %c",&acao);

        if(acao =='s'){
            continue;
        }

    }

     for(int i = 0; i < novot; i++){
        printf("%s\n", p[i].nome);
        printf("vivel: %d\nvida: %d\n\n",p[i].nivel, p[i].vida);
    }
    free(p);

    return 0;
}