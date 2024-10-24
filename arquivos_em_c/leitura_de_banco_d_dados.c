#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int nome;
    int matricula;
    int curso;
}rejistro;

void testa_arquivo(FILE *arqui,rejistro *alunos){

    if(arqui==NULL){

        printf("falha ao abrir o arquivo!!\n\n");
        free(alunos);
    }

    else{
        
        printf("arquivo abetro com suceso!!\n\n");

    }
}

void testa_alocacao(rejistro *alunos){

    if(alunos==NULL){

        printf("erro ao alocar memoria!!\n\n");

        return 0;
    }

    else{

        printf("memoria alocada com sucesso!!\n\n");

    }
}

int main(int argc,char **argv){

    if(argc<4){
        printf("informe o tamnaho desejado, inicio do rand, o fim do rando e o nome de arquivo t/ir/fr/arqui.");
        return 1;
    }

    int tamanho=atoi(argv[1]);

    int inicio=atoi(argv[2]),fim=atoi(argv[3]);

    rejistro *alunos = NULL;
    
    FILE *arquivo = NULL;

    srand(time(NULL));


    alunos = malloc(tamanho * sizeof(rejistro));

    testa_alocacao(alunos);

    arquivo = fopen(argv[4],"w");

    testa_arquivo(arquivo,alunos);

    for(int i = 0 ; i<tamanho ; i++ ){

        alunos[i].matricula = inicio + rand()% fim;

        alunos[i].nome = i;

        alunos[i].curso = inicio + rand()% fim;

        fprintf(arquivo,"nome: -%d\nmatricula: %d\ncurso: %d\n\n",alunos[i].nome+1,alunos[i].matricula,alunos[i].curso);
    }

    fclose(arquivo);
    free(alunos);

    //vesao 1.2

    return 0;
}