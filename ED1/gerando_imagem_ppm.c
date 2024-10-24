#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *arq;

    int i =0, j=0;

    arq = fopen("imagem_emppm.ppm","wt");

    fprintf(arq,"P3\n640 480\n255\n");

    for(j = 0; j < 480; j++){

        for(i = 0; i < 640; i++){
           
            fprintf(arq,"%d %d %d ",j%255,j%64+191,255-j%255);
        }
    }

    fclose(arq);

    return 0;
}