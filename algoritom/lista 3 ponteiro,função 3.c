#include <stdio.h>


void *strcpy(char *cop,char *ori){
    int i=0;
    while(ori[i]!='\0'){
        cop[i]=ori[i];
        i++;
    }
}


int main(){

    char nome[30],copia[30];

    printf("\ndigite um  nome:");
    gets(nome);
    *strcpy(copia,nome);
    puts(copia);
  
    return 0;
}