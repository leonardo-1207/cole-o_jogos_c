#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que leia um arquivo que contenha as dimensões de uma matriz (linha e coluna), a quantidade de posições que serão anuladas e as posições a serem anuladas. Em seguida, imprima na tela uma matriz com essas dimensões onde as posições não-nulas são preenchidas com 1 e as nulas com 0.*/

void imprime(int **matriz, int linha, int coluna){

    for(int l = 0; l < linha; l++) {
        for(int c = 0; c < coluna; c++) {

            printf("%4d", matriz[l][c]);
        }
        printf("\n");
    }
}

int main(){

    FILE *arquivo = fopen("t1.txt", "r");
    int linha, coluna, posi_anulados, ln, cn;
    int **m;

    if(!arquivo) {
        printf("erro na abertura do arquivo.");
        return -1;
    }

    fscanf(arquivo, "%d", &linha);
    fscanf(arquivo, "%d", &coluna);
    fscanf(arquivo, "%d", &posi_anulados);


    m = (int **) malloc(sizeof (int *) * linha);
    if(!m) {
        printf("arro na alocacao de memoria.");
        return -1;
    }

    for(int i = 0; i < linha; i++) {
        m [i] = (int *) malloc(sizeof (int ) * coluna);
        if(!m[i]) {
            printf("erro na alocacao.");
            free(m);
            return -1;
        }
    }

    for(int l = 0; l < linha; l++) {
        for(int c = 0; c < coluna; c++) {    
              fscanf(arquivo, "%d", &ln);
        fscanf(arquivo, "%d", &cn);

        m [ln][cn] = 0;
            
            m [ln][cn] = 1;
            
        }
    }



    imprime(m,linha,coluna);

    for(int i = 0; i < linha; i++) {
        free(m[i]);
    }

    free(m);

    fclose(arquivo);

    return 0;
}