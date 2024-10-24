#include <stdio.h>
#include <stdlib.h>

//ta na 3/4;

typedef struct{

    char tipo[3];
    int largura;
    int altura;
    int maxcolor;
    int **matriz;
}imagem;

void carrega_imagem(imagem* ilista){

    FILE* arquivo = fopen("hipismo.ppm","r");

    if(!arquivo){
        printf("erro au abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%s", ilista->tipo);

    fscanf(arquivo, "%d %d", &ilista->largura, &ilista->altura);

    fscanf(arquivo, "%d", &ilista->maxcolor);

    ilista->matriz = (int **) malloc(sizeof(int) * ilista->altura);

    if(!ilista->matriz){
        printf("erro na alocao das linhas.\n");
        exit(1);
    }

    for(int i = 0; i < ilista->altura; i++){
        
        ilista->matriz[i] = (int *) malloc(sizeof(int*) * ilista->largura);
        if(!ilista->matriz[i]){
            printf("erro na alocao das colunas.\n");
            exit(1);
        }

        for(int j = 0; j < ilista->largura; j++){

            fscanf(arquivo, "%d", &ilista->matriz[i][j]);
        }
    }
    fclose(arquivo);
}

int main(){

    imagem ilista;

    carrega_imagem(&ilista);

   /* for(int i = 0; i < ilista.altura; i++){
        for(int j = 0; j < ilista.largura; j++){
            printf("%d ", ilista.matriz[i][j]);
        }
        printf("\n");
    }*/


    for(int i = 0; i < ilista.altura; i++){
        free(ilista.matriz[i]);
    }

    free(ilista.matriz);

    return 0;
}