#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[20];
    int idade;
    char sexo;
}pessoa;


int main(){

FILE *arquivo = fopen("teste_binario.txt","w");
pessoa p1;

strcpy(p1.nome,"luciane lima");
p1.idade = 35;
p1.sexo ='F';

fwrite(&p1,sizeof(pessoa),1,arquivo);

printf("nome:%s\nidade:%d\nsexo:%c",p1.nome,p1.idade,p1.sexo);
fclose(arquivo);

return 0;

}