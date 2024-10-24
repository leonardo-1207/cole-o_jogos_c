#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 7

//implemente lista emcadeadas;V

typedef struct
{
    char Banda[255];
    char Titulo[255];
    char Link[255];
    struct videoclipe *prox;
} videoclipe;

videoclipe* incere_niucio(videoclipe* banco, FILE *arquivo){
    
    arquivo = fopen("data.dat","rt");

    for(int i = 0; i < TAMANHO; i++){
        
        videoclipe* aux;
        aux = (videoclipe *) malloc(sizeof(videoclipe));
    
        fgets(aux-> Banda, 100, arquivo);
        fgets(aux-> Titulo, 100, arquivo);
        fgets(aux-> Link, 100, arquivo);

        aux->Banda[strcspn(aux->Banda, "\n")] = '\0';
        aux->Titulo[strcspn(aux->Titulo, "\n")] = '\0';
        aux->Link[strcspn(aux->Link, "\n")] = '\0';

        aux -> prox = banco;
        banco = aux;
        aux = NULL; 
    }

    fclose(arquivo);
    return banco;
}

videoclipe* incere_fim(videoclipe* banco, FILE* arquivo){

    arquivo = fopen("data.dat","rt");
    if(!arquivo){
        printf("erro au abris o arquivo.\n");
        return banco;
    }

    videoclipe *aux;
    videoclipe *aux2;

    while(1){

        aux = (videoclipe*) malloc(sizeof(videoclipe));
        if(!aux){
            printf("erro ao alocar memoria.\n");
            fclose(arquivo);
        }

        if(fgets(aux->Banda, 100, arquivo) == NULL){
            free(aux);
            break;
        }
        aux->Banda[strcspn(aux->Banda, "\n")] = '\0';

        if(fgets(aux->Titulo, 100, arquivo) == NULL){
            free(aux);
            break;
        }
        aux->Titulo[strcspn(aux->Titulo, "\n")] = '\0';

        if(fgets(aux->Link, 100, arquivo) == NULL){
            free(aux);
            break;
        }
        aux->Link[strcspn(aux->Link, "\n")] = '\0';

        aux -> prox = NULL;

        if(banco == NULL){
            banco = aux;
        }

        else{

            aux2 = banco;
            while(aux2 -> prox != NULL){
                aux2 = aux2 -> prox;
            }
            aux2 -> prox = aux;
        }
    }

    fclose(arquivo);
    return banco;
}

void mostra_lista(videoclipe* banco){

    videoclipe *aux;
    int cont = 1;

    if(banco){

        aux = banco;

        do{
            printf("\nvedeo clipe %d\n%s\n%s\n%s\n\n",cont, aux->Banda, aux->Titulo, aux-> Link);
            aux = aux -> prox;
            cont ++;

        }while(aux != NULL);
    }
}

void libera_lista(videoclipe* banco){

    videoclipe* aux;
    while(banco != NULL){

        aux = banco;
        banco = banco -> prox;
        free(aux);
    }
}

int main(void)
{
    FILE *arquivo;
    videoclipe* banco = NULL;
    
    banco = incere_fim(banco, arquivo);
   
    mostra_lista(banco);
    libera_lista(banco);

   return 0;
}