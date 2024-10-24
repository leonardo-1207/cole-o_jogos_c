#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char *nome;
    char *programador_designer;
    char *fabricante;
    int ano;
    char *genero;
    struct jogoatari* prox;
}jogoatari;

jogoatari* inicializa_lista(jogoatari* plista,char* nome, char* pro, char* fab, char* genero, int anoo){

    jogoatari* aux = (jogoatari *) malloc(sizeof(jogoatari));
    if(!aux){
        printf("erro na alocaoa de memoria do nodo.\n");
        return plista;
    }
    
    aux->nome = (char *) malloc(sizeof(char) * 100);
    if(!aux->nome){
        printf("erro na alocao do nome.\n");
        free(aux);
        return plista;
    }

    aux->programador_designer = (char *) malloc(sizeof(char )* 100);    
    if(!aux->programador_designer){
        printf("erro na alocao de programador_designer.\n");
        free(aux->nome);
        free(aux);
        return plista;
    }

    aux->fabricante = (char *) malloc(sizeof(char) * 100);
    if(!aux->fabricante){
        printf("erro na alocao de fabricante.\n");
        free(aux->nome);
        free(aux->programador_designer);
        free(aux);
        return plista;
    }

    aux->genero = (char *) malloc(sizeof(char) * 100);
    if(!aux->genero){
        printf("erro na alocao de genero.\n");
        free(aux->nome);
        free(aux->programador_designer);
        free(aux->fabricante);
        free(aux);
        return plista;
    }

    strcpy(aux->nome, nome);
    strcpy(aux->programador_designer, pro);
    strcpy(aux->fabricante, fab);
    strcpy(aux->genero, genero);
    aux->ano = anoo;
    
    aux->prox = plista;
    plista = aux;
    aux = NULL;
    return plista;
}

jogoatari* cadastro_e_insere_incio(jogoatari* plista){

    //verifique tudo que for alocado dinamicamente;
    jogoatari* aux;
    aux = (jogoatari*) malloc(sizeof(jogoatari));

    if(!aux){
        printf("erro na alocacao de memoria.\n");
        return plista;
    }

    aux->nome = (char *) malloc(sizeof(char) * 100);
    if(!aux->nome){
        printf("erro na alocao de nome.\n");
        free(aux);
        return plista;
    }

    aux->programador_designer = (char *) malloc(sizeof(char) * 100);
    if(!aux->programador_designer){
        printf("erro na alocao de programador_designer.\n");
        free(aux->nome);
        free(aux);
        return plista;
    }

    aux->fabricante = (char *) malloc(sizeof(char) * 100);
    if(!aux->fabricante){
        printf("erro na alocao de fabricante.\n");
        free(aux->nome);
        free(aux->programador_designer);
        free(aux);
        return plista;
    }

    aux->genero = (char *) malloc(sizeof(char) * 100);
    if(!aux->genero){
        printf("erro na alocao de genero.\n");
        free(aux->nome);
        free(aux->programador_designer);
        free(aux->fabricante);
        free(aux);
        return plista;
    }

    printf("digite o nome do jogo: ");
    fgets(aux->nome, 100, stdin);
    aux->nome[strcspn(aux->nome, "\n")] = '\0';

    printf("digite o programador ou  designer: ");
    fgets(aux->programador_designer, 100 , stdin);
    aux->programador_designer[strcspn(aux->programador_designer, "\n")] = '\0';

    printf("digite o fabricante: ");
    fgets(aux->fabricante, 100, stdin);
    aux->fabricante[strcspn(aux->fabricante, "\n")] = '\0';

    printf("genero do jogo: ");
    fgets(aux->genero, 100, stdin);
    aux->genero[strcspn(aux->genero, "\n")] = '\0';

    printf("ano do jogo: ");
    scanf("%d", &aux->ano);
    while((getchar()) != '\n');

    aux->prox = plista;

    plista = aux;
    
    aux=NULL;

    return plista;
}

jogoatari* atualiza_iten(jogoatari* plista){

    jogoatari* aux = plista;
    int cont = 1, indice = 0;
    int acao = 0;

    if(!plista){
        printf("\nlista vazia.\n");
        return plista;
    }

    imprime(plista);

    printf("\ndigite o indice que deseja atualizar: ");
    scanf("%d", &indice);

    while(aux != NULL){

        if(cont == indice){

            while(acao != 6){
                printf("\n\noque deseja atualizar?\n\n");
                printf("\nnome (1)\nprogramador/designer (2)\nfabricante(3)\nano(4)\ngenero (5)\nfinalizar (6)\n");
                scanf("%d", &acao);
                while((getchar() != '\n'));

                switch(acao){

                    case 1:

                    printf("\nnome atual: %s\ndigite o nome desejado: ",aux->nome);
                    fgets(aux->nome, 100, stdin);
                    break;

                    case 2:

                    printf("\nprogramador/desigber: %s\ndegite o programador/designer: ",aux->nome);
                    fgets(aux->nome, 100, stdin);
                    break;

                    case 3:

                    printf("\nfabricante: %s\ndigite o fabricante desejado: ",aux->fabricante);
                    fgets(aux->fabricante, 100, stdin);
                    break;

                    case 4:

                    printf("\nano do jogo %d\n\ndigite o ano desejado: ",aux->ano);
                    scanf("%d", &aux->ano);
                    while((getchar()) != '\n');
                    break;

                    case 5:

                    printf("\ngenero: %s\ndigite o genero desejado: ",aux->genero);
                    fgets(aux->genero, 100, stdin);
                    break;
                }
            }
            break;
        }
        aux = aux -> prox;
        cont++;
    }
    return plista;
}

jogoatari* libera_um(jogoatari* plista){

    jogoatari* libera = plista;
    jogoatari* aux = NULL;
    int cont = 1, indice = 0;

    imprime(plista);
    printf("\n\nqual jogo deseja remover?");
    scanf("%d", &indice);

    //texta se lista ta vaiso;
    if(libera == NULL){
        return plista;
    }

    //texta se o nodo a cer removido eh o primeiro;
    if(indice == cont){
        plista = libera->prox;
        free(libera);
        return plista;
    }

    //itera ate o nodo desejado;
    while(cont != indice && libera != NULL){
        aux = libera;
        libera = libera->prox;
        cont++;
    }

    //texta se o nodo nao foi emcontrado;
    if(libera == NULL){
        return plista;
    }

    //aponta para o proximo que sera liberado e libera o nodo;
    aux->prox = libera-> prox;
    libera->prox = NULL;
    free(libera->nome);
    free(libera->programador_designer);
    free(libera->fabricante);
    free(libera->genero);
    free(libera);

    return plista;
}

jogoatari* libera_lista(jogoatari* plista){

    jogoatari* aux;
    jogoatari* libera;

    aux = plista;

    while(aux != NULL){

        libera = aux;
        aux = aux -> prox;

        free(libera->nome);
        free(libera->programador_designer);
        free(libera->fabricante);
        free(libera->genero);
        free(libera);
    }
    return NULL;
}

void consulta(jogoatari* plista){

    //testa se a lista ta vazia;
    if(!plista){
        return;
    }

    char termo[100];
    int escolha = 0, ano_b = 0;
    jogoatari* aux = plista;

    printf("deseja pesquisar por:\n");
    printf("1 - nome\n2 - programador\n3 - fabricante\n4 - genero\n5 - ano\n");
    scanf("%d", &escolha);
    while((getchar()) != '\n');

    switch(escolha){

        case 1:

        printf("dijite o nome desejado: ");
        fgets(termo, 100, stdin);
        termo[strcspn(termo, "\n")] = '\0';

        printf("jogos emcontrados:\n");
        while(aux != NULL){
            if(strstr(aux->nome,termo) != NULL){
                printf("\n%s\n",aux->nome);
            }
            aux = aux->prox;
        }
        break;

        case 2:

        printf("digite o programador desejado: ");
        fgets(termo, 100, stdin);
        termo[strcspn(termo, "\n")] ='\0';

        printf("jogos emcontrados:\n");
        while(aux != NULL){
            if(strstr(aux->programador_designer,termo) != NULL){
                printf("%s (programado por: %s)\n",aux->nome,aux->programador_designer);
            }
            aux = aux->prox;
        }
        break;

        case 3:

        printf("digite o fabricante desejado: ");
        fgets(termo, 100, stdin);
        termo[strcspn(termo, "\n")] = '\0';

        printf("jogos emcontrados:\n"); 
        while(aux != NULL){
            if(strstr(aux->fabricante,termo) != NULL){
                printf("%s (feito por: %s)\n",aux->nome, aux->fabricante);
            }
            aux = aux -> prox;
        }
        break;

        case 4:

        printf("diigte o genero desejado: ");
        fgets(termo,100,stdin);
        termo[strcspn(termo,"\n")] = '\0';

        printf("jogos emcontrados:\n");
        while(aux != NULL){
            if(strstr(aux->genero,termo) != NULL){
                printf("%s (%s)\n",aux->nome,aux->genero);
            }
            aux = aux->prox;
        }
        break;

        case 5:

        printf("digite o ano desejado: ");
        scanf("%d", &ano_b);
        while((getchar()) != '\n');

        printf("jogos emcontrados:\n");
        while(aux != NULL){
            if(aux->ano == ano_b){
                printf("%s (ano: %d)\n",aux->nome,aux->ano);
            }
            aux = aux->prox;
        }
        break;

        default:
        printf("opsao invalida.\n");
    }
}

void imprime(jogoatari* plista){

    jogoatari* aux;
    int cont = 1;

    if(plista){

        aux = plista;

        do{
            printf("%d %s.\n",cont,aux->nome);
            
            aux = aux->prox;
            cont++;

        }while(aux != NULL);
    }
    printf("\n");
} 

void grava_em_arquivo(jogoatari* plista,const char* name){
    
    FILE* arq = fopen(name,"wb");
    if(arq == NULL){
        printf("erro na abertura de arquivo.\n");
        return;
    }

    jogoatari* aux = plista;

    while(aux != NULL){
        fwrite(aux, sizeof(jogoatari) - sizeof(jogoatari*), 1, arq);
        aux = aux->prox;
    }
    
    fclose(arq);

    printf("\n\ntudo ok.\n");
}

int main(){

    jogoatari* plista = NULL;
    int fim = 0, acao;

    //10 jogos ja cadastrados para o uzuario ver/consultal/atualizar

    plista = inicializa_lista(plista,"Space Invaders", "Rick Maurer (original), Christopher Omarzu (Pepsi Invaders)","Licensed by Taito. Retooled as Pepsi Invaders for Coca-Cola in 1983.","acao" ,1980);

    plista = inicializa_lista(plista, "Human Cannonball","Unknown","Based on an unreleased arcade concept by Owen Rubin","Cannon Man", 1979);

    plista = inicializa_lista(plista, "Defender","Bob Polaro","	Licensed by Williams Electronics","Defender",1982);

    plista = inicializa_lista(plista, "Dodge 'Em","Carla Meninsky","Licensed by Namco","Dodger Cars",1980);

    plista = inicializa_lista(plista, "Golf","Michael Lorenzen","Licensed by Namco","Golf",1980);

    plista = inicializa_lista(plista, "Home Run","Bob Whitehead","Licensed by Namco","Baseball",1978);

    plista = inicializa_lista(plista, "Indy 500","	Ed Riddle","One of the nine Atari 2600 launch games","Race",1977);

    plista = inicializa_lista(plista, "Adventure","Warren Robinett","Contains first well-known Easter egg, containing the designer's name.","Adventure",1980);

    plista = inicializa_lista(plista,"Fatal run", "Steve Aguirrev", "	PAL-only release; developed by Sculptured Software", "acao", 1990);

    plista = inicializa_lista(plista, "Pac-man", "Tod Frye", "Licensed by Namco", "acao", 1982);

    while(fim == 0){
        printf("\n1 - cadastrar novo iten\n2 - atualizar um iten\n3 - remover um item\n4 - cosulta\n5 - ver todos os itens\n6 - finalizar\n");
        scanf("%d", &acao);

        while((getchar()) != '\n');

        switch(acao){

            case 1:

            plista = cadastro_e_insere_incio(plista);
            printf("jogo adicionado.\n\n");
            break;

            case 2:

            plista = atualiza_iten(plista);
            printf("jogo atualizado.\n\n");
            break;

            case 3:
            plista = libera_um(plista);
            printf("jogo removido.\n\n");
            break;

            case 4:
            consulta(plista);
            break;

            case 5:

            printf("jogos na lista.\n\n");
            imprime(plista);
            break;

            case 6:

            fim = 1;
            break;
        }
    }

    grava_em_arquivo(plista,"structs.bin");

    plista = libera_lista(plista);

    char* str_path_e_nome_da_imagem = "https://pt.pinterest.com/pin/146718900350205587/";
    char* str_arg = (char*)malloc(256);
    strcpy(str_arg, "explorer "); // xdg-open no linux
    strcat(str_arg, str_path_e_nome_da_imagem);
    system(str_arg);

    str_path_e_nome_da_imagem = "https://br.pinterest.com/pin/462322718003606347/";
    strcpy(str_arg, "explorer "); // xdg-open no linux
    strcat(str_arg, str_path_e_nome_da_imagem);
    system(str_arg);

    return 0;
}