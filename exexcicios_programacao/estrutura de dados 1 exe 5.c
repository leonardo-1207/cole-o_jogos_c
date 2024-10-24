/*16. Leia uma cadeia de caracteres e converta todos os caracteres para maiuscula. ´ Dica:
subtraia 32 dos caracteres cujo codigo ASCII est ´ a entre 97 e 122.*/
#include <stdio.h>

int main(){

    char nome[20];

    printf("diigte um nome:");
    gets(nome);

    for(int i=0;nome[i]!='\0';i++){
        nome[i]-=32;
    }

    puts(nome);

    return 0;
    //retirado de: https://www.facom.ufu.br/~backes/wordpress/ListaC05.pdf
    //motivo da ecolha: praticar strings.
}