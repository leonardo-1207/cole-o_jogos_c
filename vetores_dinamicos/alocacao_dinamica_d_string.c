#include <stdio.h>
#include <stdlib.h>

/*crie uma string dinamica*/

int main(){

  //ponteiro para ponteiro.
  char **nomes;
  int t=8;

  //scanf("%d",&t);
  //coloca NULL no bafer do tecaldo.
  //setbuf(stdin,NULL);


  //aloca espaco para todos os nomes desejados
  nomes = malloc(1*sizeof(char*));

  //aloca o tamnahho dos nos desejados
  nomes[0] = malloc(t*sizeof(char));

  printf("digite um nome:");
  gets(nomes[0]);

  puts(nomes[0]);

  //primerio libere todos os nomes
  free(nomes[0]);

  //depois livere o ponteiro para os nomes
  free(nomes);

  /*esta documentado assim para nao esquecer, pois acabei de aprender alocacao dinamica com strig.*/

  return 0;
}