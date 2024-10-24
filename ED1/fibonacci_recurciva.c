#include <stdio.h>

int  fibonacci(int fibonaci,int a,int b,int c){

    if(fibonaci == 0){
        return 0;
    }
    
    if(fibonaci == 1){
        return c;
    }

    c = a + b;
    a = b;
    b = c;
    return fibonacci(fibonaci-1,a,b,c);
}


int main(){

   int a = 0, b = 1, c = 0,fib = 0;
   printf("\nCALCULA FIBOMACCI.\n\ndigitr o numero desejado : ");
   scanf("%d",&fib);

   printf("\n%d\n",fibonacci(fib,a,b,c));


    return 0;
}