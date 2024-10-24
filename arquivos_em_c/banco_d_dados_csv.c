#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


typedef struct{

    int nome;
    int matricula;
    int curso;

}rejistro;

int gera_dados_aleatorios(rejistro *alu){

    alu->nome = rand()%100;
    alu->matricula = 2000 + rand()%1000;
    alu->curso = rand()%100;
    return 0; 
}


int main(int argc,char **argv){
    
    if(argc < 3){
        printf("profavor informe o numero de o numero de alunos e o nome do arquivo.csv.\n");
        return 1;
    }

    int COLUNAS = 3;

    FILE *arquivo = fopen(argv[2], "w");

    if(arquivo == NULL){
        printf("erro ao abrir o arquivo!!");
        return 1;
    }

    int tamanho = atoi(argv[1]);
    
    rejistro **alunos = malloc(tamanho * sizeof(rejistro*));

    if(alunos == NULL){
        printf("erro na alocacao de linhas!\n\n");
        return 1;
    }
    
    for(int i = 0; i < tamanho; i++){
        alunos[i] = NULL;
    }

    for(int i = 0; i < tamanho; i++){
        alunos[i] =  malloc(COLUNAS * sizeof(rejistro));
        if(alunos[i] == NULL){
            printf("erro na alocacao das colunas!!");
            return 1;
        }
    }

    for(int i = 0; i < tamanho; i++){
        gera_dados_aleatorios(&alunos[i][0]);
        gera_dados_aleatorios(&alunos[i][1]);
        gera_dados_aleatorios(&alunos[i][2]);

        fprintf(arquivo, "nome:%d,%d,%d,\n", alunos[i][0].nome, alunos[i][1].nome, alunos[i][2].nome);
        fprintf(arquivo, "matrula:%d,%d,%d,\n", alunos[i][0], alunos[i][1].matricula, alunos[i][2].matricula);
        fprintf(arquivo, "curso:%d,%d,%d,\n", alunos[i][0].curso, alunos[i][1].curso, alunos[i][2].curso);
    }

    for(int i = 0; i < tamanho; i++){
        free(alunos[i]);
    }

    free(alunos);
    fclose(arquivo);

    printf("ok");
    
    return 0;
}