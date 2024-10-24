#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

int i,*vec;
srand(time(NULL));

vec = calloc(10,sizeof(int));

if(vec){

    for(i=0;i<10;i++){
        *(vec+i) = 1+ rand() %10;
    }

    for(i=0;i<10;i++){

        printf("%4d",*(vec+i));
    }
}

else{
    printf("erro!!");
}

free(vec);

return 0;
    //usado como base o exexcico anterior"exe 6" porem com outro comando, dessa ves utilizando o CALLOC.
    //canal"Programe seu futuro", link do video:https://youtu.be/Co8Uuzs34qM?si=dJJiIAfIc4LcngZh
    //motivo da escolha: não domino bem a materia de alocação dinâmica.

}