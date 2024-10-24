#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*Defina uma struct para itens de jogo com atributos como nome, tipo e
quantidade. Crie um vetor dinâmico para armazenar o inventário de um
personagem. Implemente funções para adicionar, remover e listar itens no
inventário.*/

typedef struct{
    char nome[100];
    char tipo[100];
    int quantidade;
}itens;


void adicionar_item(itens *invet){
    int slotVasio = -1;

    for(int i = 0; i < 9; i++){
        if(strlen(invet[i].nome) == 0){
            slotVasio = i;
            break;
        }
    }

    if(slotVasio == -1){
        printf("inventario cheio.\n");
        return ;
    }

    printf("nome do item:");
    fprintf(invet[slotVasio].nome,sizeof(invet[slotVasio].nome),stdin);
    invet[slotVasio].nome[strcspn(invet[slotVasio].nome, "\n")] = '\0';
    

    printf("tipo do intem:");
    fgets(invet[slotVasio].tipo,sizeof(invet[slotVasio].tipo),stdin);
    invet[slotVasio].nome[strcspn(invet[slotVasio].tipo, "\n")] = '\0';


    printf("quantidade:");
    scanf("%d", &invet[slotVasio].quantidade);
}

void lista_inventario(itens *invet){

    char iten[100], escolha ='s';
    while(escolha =='s'){

        printf("nome do item que deseja listar.\n\n");
        for(int i = 0;i < 9; i++){
          
            printf("%s  ", invet[i].nome);
              if(strlen(invet[i].nome) > 0){
                break;
            }
        }
        printf("\n\n");
        gets(iten);

        for(int  i = 0; i < 9; i++){
            if(strcmp(iten,invet[i].nome) == 0){
                printf("\n%s\n", invet[i].nome);
                printf("%s\n", invet[i].tipo);
                printf("possue: %d\n\n", invet[i].quantidade);
            }
        }

        printf("deseja listar outro iten? (S)(N)");
        scanf(" %c", &escolha);
    }
}

int main(){
 

    itens *inventario = (itens *) malloc(sizeof(itens) * 9);
    char escolha;

    if(!inventario){
        printf("erro na alocação.\n");
        return 1;
    }

    printf("você tem 9 slots no para usar inventario.\n");
    printf("adicionar um item, remover ou listar itens? (A) (R) (L).\n");
    scanf(" %c", &escolha);
    setbuf(stdin,NULL);
    
    adicionar_item(inventario);
    adicionar_item(inventario);
    adicionar_item(inventario);

    setbuf(stdin,NULL);

    lista_inventario(inventario);

    free(inventario);
    return 0;
}