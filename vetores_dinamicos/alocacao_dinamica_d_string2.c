#include <stdio.h>
#include <stdlib.h>

/*/*Faça um programa que receba do usuário o tamanho de uma string e chame uma função
para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o
conteúdo dessa string. O programa imprime a string sem suas vogais.*/

// site : https://gabrielbueno072.github.io/rea-aed/exercicios/lista11.pdf

void limpra_buf_do_teclado(){
    setbuf(stdin,NULL);
}


int main(){

    char *nome;
    int tamanho=0,i=0;

    printf("digite o tamanho da string:");
    scanf("%d",&tamanho);

    limpra_buf_do_teclado();

    nome=malloc(tamanho*sizeof(char));

    printf("digite um nome:");
    gets(nome);

    while(nome[i]!='\0'){
        if(nome[i]!='a'&&nome[i]!='e'&&nome[i]!='i'&&nome[i]!='o'&&nome[i]!='u'){
            printf("%c",nome[i]);
        }
        i++;
    }

    free(nome);

    return 0;
}