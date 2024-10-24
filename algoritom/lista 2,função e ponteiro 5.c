/*Faça um programa com uma função que recebe por parâmetro o
tempo de duração de uma fábrica expresso em segundos e retorna
também por parâmetro esse tempo em horas, minutos e segundos.*/
#include <stdio.h>

int tempo_trabalhado(int *s,int *m,int *h){
    int aux=*s;
    *s=0;
    while(aux>0){
        aux--;
        *s=*s+1;
        if(*s>59){
            *m=*m+1;
            *s=0;
        }
        if(*m>59){
            *h=*h+1;
            *m=0;
        }
    }
}

int main(){

    int segundos=0,minutos=0,horas=0;

    printf("\ndgite o tempo de trabalho em segundos:");
    scanf("%d",&segundos);

    tempo_trabalhado(&segundos,&minutos,&horas);

    printf("\n%d:%d:%d",horas,minutos,segundos);
    
    return 0;
}