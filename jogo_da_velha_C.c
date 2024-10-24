#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 3

void libera(char **REFmat){
    for(size_t i = 0; i < T; i++){
        free(REFmat[i]);
    }  
    free(REFmat);
}

void preenche_matris(char **REFmat){
    for(size_t l = 0; l < T; l++){
        for(size_t c = 0; c < T; c++){
            REFmat[l][c] = '#';
        }
    }
}

void imprime(char **REFmat){ 
    printf("\n    A  B  C\n\n");
    for(size_t l = 0; l < T; l++){
        switch (l){

            case 0:
            printf("1 ");
            break;
            
            case 1:
            printf("2 ");
            break;
            
            case 2:
            printf("3 ");
            break;
        }
        for(size_t c = 0; c < T; c++){
            printf("%3c",REFmat[l][c]);
        }
        printf("\n");
    }
}

void ia(char **REFmat,char caracter_ia){
    //gpt
    srand(time(NULL));
    size_t l = 0,c = 0;
    do{
        l = rand()%3;
        c = rand()%3;
    }while(REFmat[l][c] !='#');
    REFmat[l][c] = caracter_ia;
}

int converte_coodenada(char LETRA){
    switch(LETRA){

        case 'a':
        return  0;
        break;

        case 'b':
        return 1;
        break;

        case 'c':
        return 2;
        break;
    }
    return 0;
}

void inceri_no_tabuleiro(int *REFnumero, char *REFletra, char caracter,char **REFmat){
    int coluna = 0;
   coluna = converte_coodenada(*REFletra);

    if(REFmat[*REFnumero-1][coluna] != '#'){

        while(REFmat[*REFnumero-1][coluna] != '#'){
            printf("esta ja esta ocupada, tente outra");
            scanf("%d %c",REFnumero,REFletra);

            coluna = converte_coodenada(*REFletra);
        }
        REFmat[*REFnumero-1][coluna] = caracter;
    }

    REFmat[*REFnumero-1][coluna] = caracter;
}

int verifica_vencedor(char **REFmat,char caracter){
    //gpt
    for(size_t l = 0; l < T; l++){

       if(REFmat[l][0] == caracter && REFmat[l][1] == caracter && REFmat[l][2] == caracter){
        return 1;
       }
       if(REFmat[0][l] == caracter && REFmat[1][l] == caracter && REFmat[2][l] == caracter){
            return 1;
        }
    }

    if(REFmat[0][0] == caracter && REFmat[1][1] == caracter && REFmat[2][2] == caracter){
        return 1;
    }

    if(REFmat[0][2] == caracter && REFmat[1][1] == caracter && REFmat[2][0] == caracter){
        return 1;
    }

    int cheio = 1;
    for(size_t l = 0; l < T; l++){
        for(size_t c = 0; c < T; c++){
            if(REFmat[l][c] == '#'){
                cheio = 0;
            }
        }
    }

    if(cheio != 0){
        return 2;
    }
    return 0;
}

int main(){

    char caracter,caracter_ia,letra;
    int numero,turno =0;
    char **jogo_da_velha = malloc(T * sizeof(char *));
    
    if(jogo_da_velha == NULL){
        printf("erro ao alocar as linhas.\n");
    }

    for(size_t i = 0; i < T; i++){
        jogo_da_velha[i] = malloc(T * sizeof(char));

        if(jogo_da_velha[i] == NULL){
            printf("erro na alocacao de linhas.\n");
        }
    }

    printf("JOGO DA VELHA\n\nescolha um X ou O:");

    while(caracter != 'x' && caracter != 'o'){
        scanf(" %c",&caracter);
    }

    caracter_ia = (caracter == 'x') ? 'o':'x';

    preenche_matris(jogo_da_velha);
    
    do{
        imprime(jogo_da_velha);
        printf("\ndigite as cordenadas n/l:");
        scanf("%d %c",&numero,&letra);

        inceri_no_tabuleiro(&numero,&letra,caracter,jogo_da_velha);
        turno++;
        if(verifica_vencedor(jogo_da_velha,caracter) != 0){
            break;
        }

        ia(jogo_da_velha,caracter_ia);
        turno++;
        if(verifica_vencedor(jogo_da_velha,caracter) != 0){
            break;
        }

    }while(turno<9);
    
    imprime(jogo_da_velha);
    libera(jogo_da_velha);

    return 0;
}