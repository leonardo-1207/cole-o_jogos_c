#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba dois arquivos do usuário e crie um terceiro arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).*/

int main(int argc, char **argv) {

    if(argc < 3) {
        printf("nome dos arquivos: ");
        return 1;
    }

    FILE *arqui1 = fopen("t1.txt", "r");
    FILE *arqui2 = fopen("t2.txt", "r");
    FILE *saida = fopen("saida", "w");
    char caracter;
    
    if(!arqui1) {
        printf("erro ao abrir o arquivio %s",argv[1]);
        return -1;
    }

    if(!arqui2) {
        printf("erro ao abrir o arquivio %s",argv[2]);
        fclose(arqui1);
        return -1;

    }

    if(!arqui1) {
        printf("erro ao abrir o arquivio de saia");
        fclose(arqui1);
        fclose(arqui2);
        return -1;
    }

    while(fscanf(arqui1, "%c", &caracter) == 1) {
        fprintf(saida, "%c", caracter);
    }

    fprintf(saida,"\n");

    while(fscanf(arqui2, "%c", &caracter) == 1) {
        fprintf(saida, "%c", caracter);
    }

    fclose(arqui1);
    fclose(arqui2);
    fclose(saida);

    return 0;
}