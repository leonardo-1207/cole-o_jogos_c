#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo_abertura, *arquivo_saida;

    char linha[255];
    int largura, altura;
    int **imagem;

    arquivo_abertura = fopen("O.pbm","rt");

    if(arquivo_abertura == NULL){
        printf("arquivo nao exixte.");
        return -1;
    }

    fgets(linha,100,arquivo_abertura);
    fscanf(arquivo_abertura, "%i", &largura);
    fscanf(arquivo_abertura, "%i", &altura);

    imagem = (int **) malloc(sizeof(int *) * altura);
    for(int i = 0; i < altura; i++){
        imagem[i] = (int *) malloc(sizeof(int) * largura);
    }

    for(int l = 0; l < altura; l++){
        for(int c = 0; c < largura; c++){
            fscanf(arquivo_abertura, "%i", &imagem[l][c]);
        }
    }

    for(int l = 0; l < altura; l++){
        for(int c = 0; c < largura; c++){
            imagem[l][c] = 1 - imagem[l][c];
        }
    }

    arquivo_saida = fopen("saida.pbm","wt");

    if(arquivo_saida == NULL){
        printf("nao foi possivel criar o arquivo de saida");

        for(int i = 0; i < altura; i ++){
            free(imagem[i]);
        }
        free(imagem);
        fclose(arquivo_abertura);
        return -1;
    }

    fprintf(arquivo_saida,"P1\n");

    fprintf(arquivo_saida,"%d %d\n",largura,altura);

    for(int l = 0; l < altura; l++){
        for(int c = 0; c < largura; c++){
            fprintf(arquivo_saida,"%d ",imagem[l][c]);
        }

        fprintf(arquivo_saida,"\n");
    }

    for(int i = 0; i < altura; i++){
        free(imagem[i]);
    }

    free(imagem);

    fclose(arquivo_abertura);
    fclose(arquivo_saida);

    return 0;
}