#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* prox;
} node;


node* InserenoInicioLista (int elem, node* plista)
{
    node *aux;
    aux = (node *)malloc (sizeof(node));
    aux->info = elem;
    aux->prox = plista;
    plista = aux;
    aux = NULL;
    return plista;
}

node* CriaListaSimples(struct node* plista)
{

    plista=NULL;
    return plista;

}

node* RemoveLista(node* plista)
{
// incompleto, libera apenas a memoria do ponteiro para o primeiro nodo

    node* aux;

    while(plista != NULL){
        aux = plista;

        plista = plista -> prox;
        free(aux);
    }

    return NULL;
}

void MostraElementosDaLista (node* plista)
{
    int count=1;
    node *aux;

    if (plista)
    {
        aux = plista;
        do
        {
            printf ("Elemento %d = %d \n",count, aux->info);
            aux = aux->prox;
            count++;
        }
        while (aux!=NULL);
    }
}


int main(void)
{

    node *plista;

    plista= CriaListaSimples(plista);

    plista= InserenoInicioLista (7, plista);

    plista= InserenoInicioLista (3, plista);

    plista= InserenoInicioLista (3, plista);

    plista= InserenoInicioLista (1, plista);

    MostraElementosDaLista(plista);

    plista=RemoveLista(plista);

    return 0;
}