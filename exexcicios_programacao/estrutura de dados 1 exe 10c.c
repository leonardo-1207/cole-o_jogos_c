/*17. Leia um vetor de 10 posic¸oes e atribua valor 0 para todos os elementos que possu ˜ ´ırem
valores negativos.*/

#include<stdio.h>


int main(){

    int i=0,vec[10],n;

    printf("digite 10 numeros positivos ou negativos:");
    

    for(i=0;i<10;i++){
        scanf("%d",&n);
        vec[i]=n;
    }

    for(i=0;i<10;i++){
        if(vec[i]<0){
            vec[i]=0;
        }
        printf("%4d",vec[i]);
    }


    return 0;

    //retirado de :https://www.facom.ufu.br/~backes/gci007/ListaC04.pdf
    //motivo da escolha: praticar vetores.

}