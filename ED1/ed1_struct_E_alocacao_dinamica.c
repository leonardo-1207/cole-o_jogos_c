#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*1) Crie uma struct chamada documento. A mesma deverá possuir os seguintes
campos:

a) Título (string)
b) Autor (string)
c) Data (inteiro)
d) Conteúdo (uma string de 20000 caracteres)

Crie três documentos na memória utilizando malloc. Você poderá preencher o
conteúdo com caracteres aleatórios. Imprima-os e libere a memória utilizada por cada um
após o término do uso.*/

typedef struct{
    char titulo[100];
    char autor[100];
    int data;
    char *conteudo;
}Documento;

void preench(Documento *d){
   //32 ao 90;
   //concertado por chat gpt
   d->conteudo = (char *) malloc(sizeof(char) * 20000);

    for(int i = 0; i< 99; i++){

        d-> autor[i] = 65 + rand()%26;
        d-> titulo[i] = 65 + rand()%26;
    }
    d-> data = rand()%101;

    for (int i = 0; i < 20000; i++) {
        d->conteudo[i] = 65 + rand() % 26;
    }
    
    d->titulo[99] = '\0';
    d->autor[99] = '\0';
    d->conteudo[19999] = '\0';
}

void impime(Documento *d){
    printf("titulo: %s\n\n",d->titulo);
    printf("autor: %s\n\n",d->autor);
    printf("data: %d\n\n",d->data);
    printf("conteudo: %s\n\n",d->conteudo);
}

int main(){
    Documento *d1 = (Documento *) malloc(sizeof(Documento));
    Documento *d2 = (Documento *) malloc(sizeof(Documento));
    Documento *d3 = (Documento *) malloc(sizeof(Documento));
    srand(time(NULL));
    preench(d1);
    preench(d2);
    preench(d3);


    printf("documento 1:\n\n");
    impime(d1);
    printf("documento 2:\n\n");
    impime(d2);
    printf("documento 3:\n\n");
    impime(d3);

    free(d1->conteudo);
    free(d2->conteudo);
    free(d3->conteudo);

    free(d1);
    free(d2);
    free(d3);

    d1 = NULL;
    d2 = NULL;
    d3 = NULL;

    return 0;
}