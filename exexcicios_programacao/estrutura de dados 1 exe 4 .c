/*13. Ler uma frase e contar quantos caracteres sao espac¸os em brancos. Lembre-se que ˜
uma frase e um conjunto de caracteres (vetor).*/
#include <stdio.h>

int main(){
    char frase[150];
    int i=0,space=0;

    printf("digite uma frase:");
    gets(frase);

    for(i = 0;frase[i]!='\0';i++){
        if(frase[i]==' '){
            space++;
        }
    }

    printf("essa fraze com tem %d espacos em branco.",space);
   

    return 0;
    //exercicio retidado de: https://www.facom.ufu.br/~backes/wordpress/ListaC05.pdf
    //motiva da ecolha: praticra strings.
}