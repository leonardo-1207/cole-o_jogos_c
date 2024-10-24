#include <stdio.h>
#include <stdlib.h>

/*Considerando o código fornecido na última aula (listas.c):

1. Crie uma função para localizar qualquer elemento da lista.*

2. Crie uma função para inserir um novo elemento no fim de uma lista simplesmente encadeada.*

3. A partir do uso de chamadas à essa função, corrija a função que deveria remover toda a lista.*

4. Crie uma função que permita inserir elementos após uma dada posição da lista.*

5. Crie uma função para remover qualquer elemento da lista dado o valor de sua chave.*

6. trocar dois nodos de lugar utilizando apenas ponteitos.
*/

typedef struct node
{
    int info;
    struct node* prox;
} node;

node* CriaListaSimples(struct node* plista){

    plista=NULL;
    return plista;
}

node* InserenoInicioLista (int elem, node* plista){

    node *aux;
    aux = (node *)malloc (sizeof(node));
    aux -> info = elem;
    aux -> prox = plista;
    plista = aux;
    aux = NULL;
    return plista;
}

node* incere_fim_lista(int elem, node* plista){

    node* aux;
    node* aux2;

    aux = (node*) malloc(sizeof(node));
    aux -> info = elem;
    aux -> prox = NULL;

    if(!plista){
        plista = aux;
    }
    
    else{

        aux2 = plista;
        while(aux2 -> prox != NULL){
            aux2 = aux2 -> prox;
        }
        aux2 -> prox = aux;
    }

    return plista;
}

node* incere_indice_desejado(int elem, node* plista){

    int cont = 1;
    int indice = 0;

    printf("wm que posicao deseja colocar o nodo? ");
    scanf("%d", &indice);

    node* aux;
    aux = (node *) malloc(sizeof(node));
    aux -> info = elem;

    if(plista == NULL){
        aux -> prox = plista;
        plista = aux;
        aux = NULL;
    }

    else{

        node* aux2 = plista;

        while(aux2 != NULL){

            if(cont == indice-1){

                aux -> prox = aux2 -> prox;
                aux2-> prox = aux;
                break;
            }
            aux2 = aux2 -> prox;
            cont++;
        }
    }
    return plista;
}

node* RemoveLista(node* plista){

    // incompleto, libera apenas a memoria do ponteiro para o primeiro nodo*

    node *aux = plista;
    node *libera;
    
    while(aux != NULL){

        libera = aux;
        aux = aux -> prox;
        free(libera);
    }

    return NULL;
}

void MostraElementosDaLista (node* plista){

    int count=1;
    node *aux;

    if(plista)
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

void localiza_na_lista(node* plista){

    int elem = 0;
    int cont = 0;
    int achou = 0;

    printf("\n\ndigite um elemento para procurar na lista: ");
    scanf("%d", &elem);

    node* aux = plista;

  do{
        if(elem == aux -> info){
           achou = 1;
           break;
        }

        aux = aux -> prox;
        cont++;
    }while(aux != NULL);

    if(achou){
        printf("\nelemnto  %d ancontrado ecnontrado no nodo %d.\n\n",elem, cont+1);
    }

    else{
        printf("\nelemento nao encontrado.\n\n");
    }   
}

node* troca_nodo_de_lugar(node* plista, int indice1, int indice2){
    
    node* inicio = plista;
    node* meio = plista;
    node* aux = NULL;
    node* aux2 = NULL;
    int cont = 1;

    while(inicio != NULL && cont < indice1){
        aux = inicio;
        inicio = inicio -> prox;
        cont++;
    }

    cont = 1;
    while(meio != NULL && cont < indice2){
        aux = meio;
        meio = meio ->prox;
        cont++;
    }

    if(inicio == NULL || meio == NULL){
        return plista;
    }


    if (inicio != NULL) {
        aux->prox = aux2;
    } else {
        plista = aux2;
    }

    if (aux2 != NULL) {
        aux2->prox = aux;
    } else {
        plista = aux;
    }

    node* tem = aux->prox;
    aux -> prox = aux2 -> prox;
    aux2 -> prox = tem;

    
    return plista;
}

node* remove_um_node(node* plista, int chave){

    node* aux = plista;
    node* aux2 = NULL;

    if(aux != NULL && aux-> info == chave){
        plista = aux -> prox;
        free(aux);
        return plista;
    }

    while(aux != NULL && aux-> info != chave){
        aux2 = aux; 
        aux = aux -> prox;
    }

    if(aux == NULL){
        return plista;
    }

    aux2 -> prox = aux -> prox;
    free(aux);
    return plista;
}

int main(void){

    node *plista;

    plista = CriaListaSimples(plista);

    plista= InserenoInicioLista (7, plista);

    plista= InserenoInicioLista (3, plista);

    plista= InserenoInicioLista (3, plista);

    plista= InserenoInicioLista (1, plista);

    plista = incere_fim_lista(36,plista);
    plista = incere_fim_lista(88,plista);
    plista = incere_fim_lista(10,plista);
    plista = incere_fim_lista(5,plista);

    MostraElementosDaLista(plista);

    printf("\n");
    
    //plista = incere_indice_desejado(100,plista);

   // MostraElementosDaLista(plista);

    printf("\n");

    //remove_um_node(plista,10);

    plista = troca_nodo_de_lugar(plista,4,7);

    MostraElementosDaLista(plista);
    
    //localiza_na_lista(plista);
    
    plista=RemoveLista(plista);

    return 0;
}