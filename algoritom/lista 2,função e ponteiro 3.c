/*Adapte o programa anterior para que o usuário informe 3 notas do
mesmo aluno para 3 disciplinas diferentes e armazene estes valores
em uma matriz. As notas na primeira linha da matriz serão referentes
à disciplina de Português, da segunda linha à Geografia e da terceira
linha à Matemática. Passe essa matriz de notas para a função
calcularMedia e a letra, como no problema anterior. Mostre o valor
da média calculada para cada disciplina na função main.
OBS.: Repare que agora a função calcularMedia (e as demais que
ela chama) precisa retornar 3 valores de médias (uma para cada
disciplina). Avalie a melhor solução para isto.*/

#include <stdio.h>
#define NUM_L 3
#define NUM_C 3

float calculaMdeia(char letra,float m[NUM_L][NUM_C],float v[],int t){
    float soma=0;
    float soma2=0;
    int linha,coluna;
    float v2[t];
    float matriz[NUM_L][NUM_C]={{5,3,2},
                                {5,3,2},
                                {5,3,2}};
    switch(letra){
        case 'a':
        case 'A':
        for(linha=0;linha<NUM_L;linha++){
            soma=0;
            for(coluna=0;coluna<NUM_C;coluna++){
                soma+=m[linha][coluna];
            }
            v[linha]=soma;
        }

        for(int i=0;i<t;i++){
          v[i]/=t; 
        }
        break;

        case 'p':
        case 'P':
        for(linha=0;linha<NUM_C;linha++){
            soma=0;
            soma2=0;
            for(coluna=0;coluna<NUM_C;coluna++){
                m[linha][coluna]*=matriz[linha][coluna];
                soma+=m[linha][coluna];
                soma2+=matriz[linha][coluna];
            }
            v[linha]=soma;
            v2[linha]=soma2;
        }

        for(int i=0;i<t;i++){
            v[i]/=v2[i];
        }
        break;
        case 'h':
        case 'H':
        for(linha=0;linha<NUM_L;linha++){
            soma=0;
            for(coluna=0;coluna<NUM_C;coluna++){
                m[linha][coluna]/=1;
                soma+=m[linha][coluna];
            }
            v[linha]=soma;
        }
        for(int i=0;i<t;i++){
            v[i]/=t;
        }

    }
}

int main(){
    float notas[NUM_L][NUM_C];
    int linha,coluna;
    char caracter;
    float media[NUM_L];
    char continuar='s';

    while(continuar=='s'){

         for(linha=0;linha<NUM_L;linha++){
        if(linha==0){
            printf("\ndigite suas tres notas de portugues:");
        }
        else if(linha==1){
            printf("agora digite suas tres notas de geografia:");
        }
        else{
            printf("por fim suas tres notas de matematica:");
        }
        for(coluna=0;coluna<NUM_C;coluna++){
            scanf("%f",&notas[linha][coluna]);
        }
    }

        printf("'A' 'P' 'H' digite um desses caracteres:");
        scanf(" %c",&caracter);

        calculaMdeia(caracter,notas,media,3);
        printf("\n\nMEDIAS\n\nportuges:%.1f\ngeografia:%.1f\nmetematica:%.1f\n\n",media[0],media[1],media[2]);

        printf("degeja continuar calculando medias de outro aluno? 'S' 'N'\n");
        scanf(" %c",&continuar);
        switch(continuar){
            case 's':
            case 'S':
            continue;
            break;
            case 'n':
            case 'N':
            break;
        }
    }

    return 0;
}