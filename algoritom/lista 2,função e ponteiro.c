
/*Escreva um programa com uma função calcularMedia que recebe
por parâmetro (com passagem por valor), 3 notas de um aluno e
uma letra. Se a letra for A, calcule a média aritmética das notas do
aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H,
a sua média harmônica. Crie uma função independente para cada
tipo de média mencionada e faça com que as funções retornem a
média calculada.*/

#include <stdio.h>

float media_aritmetica(float a,float b,float c){
    float media=0;
    media=(a+b+c)/3;
    return media;
}

float media_ponderada(float a,float b,float c){
    float media=0;
    media=(5*a+3*b+2*c)/(5+3+2);
    return media;
}

float media_harmonica(float a,float b,float c){
    float media=0;
    media=3/((1/a)+(1/b)+(1/c));
    return media;
}

int main(){
    float n,n2,n3;
    float media;
    char acao;

    printf("\ndigite suas tes notas:");
    scanf("%f %f %f",&n,&n2,&n3);
    printf("agora digite uma letra (A) (P) (H):");
    scanf(" %c",&acao);
    switch(acao){
        case 'a':
        case 'A':
        media=media_aritmetica(n,n2,n3);
        printf("a sua media aritmetica eh essa:%f",media);
        break;
        case 'p':
        case 'P':
        media=media_ponderada(n,n2,n3);
        printf("essa eh sua media ponderada:%f",media);
        break;
        case 'h':
        case 'H':
        media=media_harmonica(n,n2,n3);
        printf("sua media harmonica:%f",media);
        break;
        default:printf("opcoa invalida.");
    }

    return 0;
}