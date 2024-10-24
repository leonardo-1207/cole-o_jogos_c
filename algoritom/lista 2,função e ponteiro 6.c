#include <stdio.h>

int define_idade(int a){
    if(a>=5&&a<=7){
        return 'A';
    }
    else if(a>=8&&a<=10){
        return 'B';
    }
    else if(a>=11&&a<=13){
        return 'A';
    }
    else if(a>=13&&a<=17){
        return 'B';
    }
    else{
        return 'B';
    }

}

int main(){
    int idade;
    char categoria;

    printf("digite sua idade:");
    scanf("%d",&idade);
    categoria=define_idade(idade);
    printf("sua categoria eh %c",categoria);

    return 0;
}