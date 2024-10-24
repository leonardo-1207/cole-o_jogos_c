/*Adapte o código do problema anterior para que as notas do aluno
informadas pelo usuário sejam armazenadas em um vetor e passe
para a função calcularMedia o vetor de notas e a letra que indica o
tipo de média a ser calculada. Mostre o valor da média calculada na
função main e, em seguida, pergunte ao usuário se ele deseja
informar notas para outro aluno (´S´ = Sim e ‘N’ = Não). Enquanto a
resposta for sim, repita todo o procedimento de cálculo da média.
OBS.: Lembre-se que a passagem de vetores (incluindo strings) e
matrizes por parâmetro para funções é sempre por referência. Ou
seja, a função recebe o endereço de memória do início do
vetor/matriz, podendo alterar diretamente seu conteúdo.*/
#include <stdio.h>

float media_aritmetica(float v[],int t){
    float media=0;
    int i;
    for(i=0;i<t;i++){
        media+=v[i];
    }
    media/=t;
    return media;
}

float media_ponderada(float v[],int t){
   float media=0;
   int v2[]={5,3,2};
   int i,soma=0;
   for(i=0;i<t;i++){
        v[i]*=v2[i];
        soma+=v2[i];
        media+=v[i];
   }
   media/=soma;

   return media;
}

float media_harmonica(float v[],int t){
    float media=0;
    for(int i=0;i<t;i++){
        v[i]/=1;
        media+=v[i];
    }
    media/=t;
    return media;
}


int main(){
    float notas[3];
    float media;
    char acao, continuar='s';

    while(continuar=='s'){
        for(int i=0;i<3;i++){
         printf("digite sua %d nomta:",i+1);
         scanf("%f",&notas[i]);
        }
        printf("agora digite uma letra (A) (P) (H):");
        scanf(" %c",&acao);
        switch(acao){
         case 'a':
         case 'A':
         media=media_aritmetica(notas,3);
         printf("a sua media aritmetica eh essa:%f\n",media);
         break;
         case 'p':
         case 'P':
         media=media_ponderada(notas,3);
          printf("essa eh sua media ponderada:%f\n",media);
          break;
          case 'h':
          case 'H':
          media=media_harmonica(notas,3);
          printf("sua media harmonica:%f",media);
          break;
          default:printf("opcoa invalida.");
        }
        printf("degeja calcular notas de outro aluno? 's'SIM 'n'NAO.");
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