#include <stdio.h>

int main(){
    char nome[30];

    printf("\ndigite alguama coisa:");
    gets(nome);
    puts(nome);
    printf("esta palavra contem %d caracteres\n",strlen(nome));


    return 0;
}