#include <stdio.h>
#include <math.h>

/*implrmrntar multiplicação ok.
    divisao ok.
    modulo.ok.
*/

typedef struct{
    double real;
    double imagi;
}cplx;

cplx soma(cplx n1, cplx n2){
    cplx m;

    m.real = n1.real + n2.real;

    m.imagi = n1.imagi + n2.imagi;

    return m;
}

cplx sub(cplx n1,cplx n2){
    cplx m;

    m.real = n1.real - n2.real;

    m.imagi = n1.imagi - n2.imagi;

    return m;
}

//multiplicação de numeros complexos;
cplx mult(cplx n1, cplx n2){
    cplx m;

    //multiplica real por real e imagi por imagi;
    //(a.r * b.r) - (a.i * b.i)
    m.real = ((n1.real * n2.real) - (n1.imagi * n2.imagi));

    //multplica real por imagi e imagi por real;
    //(a.r * b.i - b.i * a.r)
    m.imagi = (n1.real * n2.imagi + n2.imagi * n1.real);
    
    return  m;
}

cplx div(cplx n1,cplx n2){
    cplx m;

    m.real = (((n1.real * n2.real) + (n1.imagi * n2.imagi)) / (n2.real * n2.real + n2.imagi * n2.imagi));
    
    m.imagi = ((-(n1.real * n2.real) + (n1.imagi * n2.real)) / (n2.real * n2.real + n2.imagi * n2.imagi));

    return m;
}

cplx modulo(cplx n1){
    double m;
    cplx resultado;

    m = n1.real * n1.real + n1.imagi * n1.imagi;
    resultado.real = sqrt(m);
    resultado.imagi = sqrt(m);
    return resultado;
}

void mostra(cplx n){
    printf("\n\nZ = %.2f %.2fi\n\n",n.real,n.imagi);
}

int main(){
    cplx a,b,c;

    a.real = 3;
    a.imagi = 4;

    b.real = 2;
    b.imagi = -5;

    c = soma(a,b);

    mostra(c);

    return 0;
}