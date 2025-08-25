#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double f(double x){
    return (x * x ) - 2;
}

double derivada(double x){
    return 2 * x;
}

int main(){
    double epsilon = 0.001;
    double xn[100];
    int i = 0;
    
    xn[i] = 2;

    double fXn;

    do{
        i++;
        xn[i] = xn[i - 1] -  f(xn[i - 1]) / derivada(xn[i - 1]);
        printf("iteracao %d: x%d = %.5f\n", i, i, xn[i]);

        fXn = f(xn[i]);
        printf("%.6f\n", fXn);
        
    }while( (fabs(fXn) > epsilon )  ||  ( ( fabs(xn[i]) )  - ( fabs(xn[0]) )   >  epsilon ));

    printf("\nResulta na raiz aproximada: %.4f\n", xn[i]);

}




