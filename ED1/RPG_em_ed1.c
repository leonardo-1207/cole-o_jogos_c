#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Crie uma struct Personagem para um jogo de RPG. Inclua nessa struct o nome, a
raça, energia, pontos de experiência, magia, as coordenadas x e y em um mapa
fictício, o alinhamento1, e atributos de sua escolha. Crie uma party (um time de
quatro a seis jogadores) e um exército de 1000 inimigos para iniciar o seu jogo.
Insira todos os personagens que for criar em um vetor dinâmico. Permita mostrar as
características de qualquer um deles fornecendo o seu nome. Libere a memória
após o uso.*/

typedef struct{
    char nome[50];
    char raca[50];
    int energia;
    double pontos_de_xp;
    int magia;
    double x;
    double y;
    char alinhamento[20];
    int vida;
    int turno;
    int atk;
}Personagem;

typedef struct{
    int vida;
    int atk;
    int turno;
    int acao;
}inimigo_generico;

void preeche_inimigos(inimigo_generico *inimigos, int t){
    for(int i = 0; i < t; i++){
        inimigos[i].vida = 50 + rand()%100;
        inimigos[i].atk = 20 + rand()%10;
    }
}

void preemche(Personagem *jogadores,int t){
    int i = 0 ;
    strcpy(jogadores[0].nome,"Liza");
    strcpy(jogadores[0].raca,"humano");
    strcpy(jogadores[0].alinhamento,"Lawful Good");

    strcpy(jogadores[1].nome,"Roland");
    strcpy(jogadores[1].raca,"humano");
    strcpy(jogadores[1].alinhamento,"Neutral Good");
    
    strcpy(jogadores[2].nome,"Eirik");
    strcpy(jogadores[2].raca,"elfo");
    strcpy(jogadores[2].alinhamento,"Chaotic Neutral");

    strcpy(jogadores[3].nome,"Godefroy");
    strcpy(jogadores[3].raca,"Orc");
    strcpy(jogadores[3].alinhamento,"Lawful Evil");
    
    for( i = 0; i < 4; i++){
        jogadores[i].energia = 40 + rand()%20;
        jogadores[i].magia = 40 + rand()%20;
        jogadores[i].vida = 50 + rand()%100;
        jogadores[i].atk = 20;
    }

    if(t == 6){
        strcpy(jogadores[4].nome,"William");
        strcpy(jogadores[4].raca,"humano");
        strcpy(jogadores[4].alinhamento,"Lawful Evil");

        strcpy(jogadores[5].nome,"Gawain");
        strcpy(jogadores[5].raca,"Vampiro");
        strcpy(jogadores[5].alinhamento,"Chaotic Evil");

        for( i = i ; i < t; i++){
            jogadores[i].energia = 40 + rand()%20;
            jogadores[i].magia = 40 + rand()%20;
            jogadores[i].vida = 50 + rand()%100;
            jogadores[i].atk = 20;
        }
    }
}

void mostra_personagem(Personagem *jogadores,int t){
    
    printf("\nNome: %s\n",jogadores[t].nome);
    printf("raca: %s\n",jogadores[t].raca);
    printf("alinhamento: %s\n",jogadores[t].alinhamento);
    printf("vida: %d\n",jogadores[t].vida);
    printf("energia: %d\n",jogadores[t].energia);
    printf("magia: %d\n\n",jogadores[t].magia);    
}

void mostra_em_sequencia(Personagem *jogadores){
    for( int i = 0; i < 4; i++){
        printf("%s  ",jogadores[i].nome);
    }
}

void mostra_inimigos(inimigo_generico *inimigo,int j){
    printf("         inimigo generico\n%d:vida\n%d:atk",inimigo[j].vida,inimigo[j].atk);
}

int main(){
    Personagem *jogadores = NULL;

    inimigo_generico *inimigos = (inimigo_generico *) malloc(sizeof(inimigo_generico) * 1000);
    
    int tam_do_time = 4,  fim = 0,j=0;
    
    char nome[50], acao;

    srand(time(NULL));

    printf("\nforme um time de no minimo 4 a 6 jogadores.\n\nquantos jogadores vao cer? ");

  /*  while(tam_do_time != 4 && tam_do_time != 6){
        scanf("%d",&tam_do_time);
    }*/

    jogadores = (Personagem *) malloc(sizeof(Personagem) * tam_do_time);

    preemche(jogadores,tam_do_time);

    preeche_inimigos(inimigos,1000);

    printf("\n\npara escolher com quem quer jogar digite I e o nome do personagem.");

    printf("\nseu time.\n\n");

    while(fim == 0){

        //na main funciona.

        mostra_em_sequencia(jogadores);

        mostra_inimigos(inimigos,j);

        scanf(" %c",&acao);

            inimigos[j].acao = (rand() % 3) + 1;

            switch(acao){

            case 'i':

                printf("digite o nome desejado: ");
                scanf("%s",nome);

                for(int i = 0; i < tam_do_time; i++){

                    if(strcmp(nome,jogadores[i].nome) == 0){

                        mostra_personagem(jogadores,i);
                    }
                }
            continue;

            case 'j':

            if(inimigos[j].acao == 1){

                printf("os dois atacaram\n os dois sofrem dano.");

                for(int i = 0; i < tam_do_time; i++){

                    if(strcmp(nome,jogadores[i].nome) == 0){

                        jogadores[i].vida -= inimigos[j].atk;
                    }
                }
            }
            
            break;

        }
        
    }

    printf("\n");
    
    free(jogadores);

    free(inimigos);

    printf("\nok\n");

    return 0;
}