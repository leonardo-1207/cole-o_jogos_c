#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vetPar(int *v1,int *v2,int *v3,int t){
    int i=0,j=0,p=0;
    
    for(i=0;i<t;i++){
        
        if(v1[i]%2==0){
            v2[j]=v1[i];
            j++;
        }
        
        else if(!v1[i]%2==0){
            v3[p]=v1[i];
            p++;
        }
       
    }
}


int main(){
    int v1[10],v2[10],v3[10];
    int i;

    srand(time(NULL));

    printf("primeiro vetor.\n");

    for(int i=0;i<10;i++){
        v1[i]=1+rand() %100;
        printf("%5d",v1[i]);
        v2[i]=0;
        v3[i]=0;
    }

    vetPar(v1,v2,v3,10);

    printf("\n\nsegundo vetro.\n");

    for(i=0;i<10;i++){
        printf("%5d",v2[i]);
    }

    printf("\n\nterceiro vetro.\n");

    for(i=0;i<10;i++){
        printf("%5d",v3[i]);
    }

    return 0;
}