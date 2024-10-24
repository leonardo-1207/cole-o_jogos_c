/*Preencha um vetor de 10 elementos com valores inteiros fornecidos pelo
usuário e passe esse vetor para uma função. Esta função deve mostrar na
tela todos os valores do vetor utilizando um ponteiro definido localmente,
dentro da função. */

#include <stdio.h>

void inprime_vetr(int v[],int t){
    int *ptr=NULL;
    ptr=v;
    printf("\n%d\n",*ptr);

    ptr=&v[1];
    printf("%d\n",*ptr);

    ptr=&v[2];
    printf("%d\n",*ptr);

    ptr=&v[3];
    printf("%d\n",*ptr);

    ptr=&v[4];
    printf("%d\n",*ptr);
    ptr=NULL;
}




int main(){

    int numero[5];
    int i;
    printf("preencha o  vetor de 5 posisoens:");
    for(i=0;i<5;i++){
        scanf("%d",&numero[i]);
    }

   inprime_vetr(numero,5);

    return 0;
}