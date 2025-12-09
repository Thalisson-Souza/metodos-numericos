#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double f(double x){
    return sin(x) - exp(x);
}

double f_derivada(double x){
    return cos(x) - exp(x);
}

int main(){
    double epsilon = 0.001;
    double xn[100];
    int i = 0;
    double fXn;
    
    xn[i] = 10;

    do{
        double derivada = f_derivada(xn[i]);

        if(fabs(derivada) < 0.000001){
            printf("deu ruim aqui -> f linha(%.6f) = 0\n", xn[i]);
            return 0;
        }

        i++;
        xn[i] = xn[i - 1] -  f(xn[i - 1]) / derivada;
        fXn = f(xn[i]);

        printf("iteracao %d: x%d = %.6f  ---  f(x%d) = %.6f\n", i, i, xn[i], i, fXn);
        
    }while(fabs(f(xn[i])) > epsilon || fabs(xn[i] - xn[i-1]) > epsilon);

    printf("\nResulta na raiz aproximada: %.6f\n", xn[i]);

}




