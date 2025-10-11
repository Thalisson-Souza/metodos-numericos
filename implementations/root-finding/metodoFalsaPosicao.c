#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
    Formula: Falsa posição
    x1 = a f(b) - b f(a) 
        ----------------
        f(b) - f(a)
*/

double f(double x){
    return (x * x) - 2;
}

double XnfalsaPosicao(double a, double b){
    double fA = f(a);
    double fB = f(b);

    double x1 = ( (a * fB) - (b * fA) ) / (fB - fA);
    return x1;
}


int main(){
    double a = 1.41;
    double b = 3;
    double epson = 0.001;

    double x, fX, fA, fB;
    int iteracoes = 0;

    do{
        iteracoes++;
        fA = f(a);
        fB = f(b);

        x = XnfalsaPosicao(a, b);
        fX = f(x);

        printf("Iteracoes %d: a = %.6f | b = %.6f | x = %.6f | f(x) = %.6f\n", iteracoes, a, b, x, fX);

        if(fabs(fX) < epson){
            printf("\nA raiz aproximada x: %.6f\n", x);
            printf("Raiz exata da f(x) = x^2 - 2 = 0, (sqrt(2)) = %.6f\n", sqrt(2));
            printf("Erro absoluto = %.6f\n", fabs(x - sqrt(2)));
            break;
        }if(fA * fX < 0){
            b = x;
        }else if(fX * fB < 0){
            a = x;
        }
    }while(fabs(b - a) > epson);

}