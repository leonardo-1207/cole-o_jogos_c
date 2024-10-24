#include <stdio.h>
#include <stdlib.h>

// TAREFAS:
// 1. Crie o trecho de código que libera a memória após o uso

// 2. Crie uma struct para imagem, com o tipo, largura, altura e os dados.

// 3. Separe o código em funções individuais para inicializar a imagem, ler, invertê-la e gravar em disco

// 4. Note que o código usa o armazenamento de dados de maneira MUITO ineficiente. (um int de 4 bytes para um único dígito 1 ou 0). Descubra como armazenar esses dados binários na memória,

// agrupando-os de 8 em 8 (bytes). Dica: um unsigned char ocupa um byte. Existem pelo menos duas formas distintas de fazê-lo.

// 2 - crie uma struct para a imagem contedo
// largura
//altura
// e seus dados

typedey struct {




}imagem;




int main(void)
{
    FILE* arq1, *arq2;
    int** matriz;
    int i,j,largura,altura;
    arq1=fopen("o.pbm","rt");
    arq2=fopen("o1.pbm","wt");
    char header[5];

    fgets(header,5,arq1);
    fscanf(arq1,"%i %i",&largura,&altura);


    matriz=(int**)malloc(sizeof(int*)*largura);
    for (i=0; i<largura; i++)
        matriz[i]=(int*)malloc(sizeof(int)*altura);


    for (j=0; j<altura; j++)
        for (i=0; i<largura; i++)
            fscanf(arq1,"%i",&(matriz[i][j]));

    fprintf(arq2,"%s\n%d %d\n",header, largura, altura);

    for (j=0; j<altura; j++)
    {
        for (i=0; i<largura; i++)
        {
            fprintf(arq2,"%i ",1-matriz[i][j]);
        }
        fprintf(arq2,"\n");
    }

    fclose(arq1);
    fclose(arq2);

    //1- liberara a memoria.
    for(int i = 0; i < largura; i ++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}