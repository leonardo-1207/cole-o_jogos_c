#include <stdio.h>
#include <stdlib.h>

//7. Inverter uma dada string

int inverte_string(char *string,int inicio,int fim,char aux){
  
    if(inicio >= fim){
        
        return 0;
    }

    aux = string[inicio];

    string[inicio] = string[fim-1];
    
    string[fim-1] = aux;

    return inverte_string(string,inicio+1,fim-1,aux);
}

int main(){

    char nome[20],aux = '0';
    
    int i = 0;

    printf("digite um nome:");
    
    gets(nome);
    
    for(i = 0; nome[i] != '\0'; i++);

    puts(nome);

    inverte_string(nome,0,i,aux);
    
    puts(nome);

    return 0;
}