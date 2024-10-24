#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 7

/*inplemente listas encadeadas no lugar de vetores dinâmicos*/

typedef struct
{
    char Banda[255];
    char Titulo[255];
    char Link[255];
    struct videoclipe *proximo;
} videoclipe;


videoclipe* incere(videoclipe *p, FILE *arq){

}

int main(void)
{
    FILE *arquivo;
    int i=0;
    videoclipe* banco;

    banco=(videoclipe*)malloc(sizeof(videoclipe)*7);

    arquivo = fopen ("data.dat","rt");

    for (i=0; i<TAMANHO; i++)
    {
        printf("%d\n",i);
        fgets(banco[i].Banda,100,arquivo);
        fgets(banco[i].Titulo,100,arquivo);
        fgets(banco[i].Link,100,arquivo);
    }
    printf("Leu tudo\n");
    for (i=0; i<TAMANHO; i++)
    {
        printf("Registro %d\n",i);
        printf("%s",banco[i].Banda);
        printf("%s",banco[i].Titulo);
        printf("%s",banco[i].Link);
    }

    fclose(arquivo);

    free(banco);

    return 0;

}