#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double f(double x){
    return (x * x ) - 2;
}

int main(){
    double episilon = 0.001;
    double x[100];
    x[0] = 1.0;
    x[1] = 2.0;

    int k = 1;

    printf("Iteracao %d: x0 = %.6f, f(x0) = %.6f\n", 0, x[0], f(x[0]));
    printf("Iteracao %d: x1 = %.6f, f(x1) = %.6f\n", 1, x[1], f(x[1]));
    do{
        x[k + 1] = x[k] - f(x[k]) * (x[k] - x[k - 1]) / (f(x[k]) - f(x[k - 1])); 
        k++;        
    
        printf("Iteracao %d: x = %.6f, f(x) = %.6f\n", k, x[k], f(x[k]));

    }while(fabs(f(x[k])) > episilon && fabs(x[k] - x[k-1]) > episilon);


    printf("\nA raiz aproximada eh: %.6f\n", x[k]);

}