#include <stdio.h>

/*16 - Faça um algoritmo que leia três valores que representam os três lados de um triângulo e verifique se são válidos, determine se o triângulo é 

equilátero, isósceles ou escaleno.*/


int main(){
   int vet[3];
   int dias=0,mes=0,anos=0,ano=0;

   printf("digite sua data de nacimento.(dia/mes/ano)\n");
   for(int i=0; i<3;i++){
      scanf("%d",&vet[i]);
   }

   while(anos != 2024-vet[2]){

      dias++;
      if(dias>=30){
         mes++;
        dias = 1;
      }

      if(mes>=12){
         ano++;
         mes = 1;
      }

      if(dias== vet[0] && mes == vet[1]){
         anos++;
      }
   }

   printf("%d anos.\n%d dias.\n %d meses.\n",anos,dias,mes);

   return 0;
}