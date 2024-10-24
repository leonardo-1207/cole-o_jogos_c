/*. Faça uma função que recebe, por parâmetro, a hora de início e a
hora de término de um jogo, ambas subdivididas em 2 valores
distintos: horas e minutos. O procedimento deve retornar, também
por parâmetro, a duração do jogo em horas e minutos, considerando
que o tempo máximo de duração de um jogo é de 24 horas e que o
jogo pode começar em um dia e terminar no outro.
*/
//7
#include <stdio.h>
void tempoJogado(int HoraI,int MinI,int HoraT,int MinT,int *Horaj,int *MinJ){
    int aux=0,s=0;
    *Horaj=HoraT-HoraI;

    aux=(MinI+MinT)*60;
    while(aux>0){
        aux--;
        s++;
        if(s>59){
            *MinJ=*MinJ+1;
            s=0;

        }
        if(*MinJ>59){
            *MinJ=0;
        }
    }

}



int main(){
    int horaDeInicio,minutosDinicio,hora_termino,minutos_termino,horasJodas,minutos;


    printf("\ndigite a hora de inicio do jogo:");
    scanf("%d",&horaDeInicio);
    printf("\ninforme os minutos tabme:");
    scanf("%d",&minutosDinicio);

    printf("\nagora a hora de termino:");
    scanf("%d",&hora_termino);
    printf("\nminutos de termino:");
    scanf("%d",&minutos_termino);

    tempoJogado(horaDeInicio,minutosDinicio,hora_termino,minutos_termino,&horasJodas,&minutos);
    printf("\nvoce jogou %d horas e %d minutos hoje",horasJodas,minutos);

    return 0;
}