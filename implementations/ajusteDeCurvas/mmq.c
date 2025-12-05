#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../linear-system-equations/gauss.h"

// gcc .\ajusteDeCurvas\mmq.c .\linear-system-equations\gauss.c -lm -o MMQ
// ./MMQ


void substituicao(int n, double A[][MAX + 1], double x[]){
    for(int i = n-1; i >= 0; i--){
        double soma = 0;
        for(int j = i+1; j < n; j++){ // soma os valores já encontrados x[j] * coeficiente
            soma += A[i][j]*x[j];
        }
        x[i] = (A[i][n]-soma)/A[i][i];  // isola x[i] para resolver ela
    }
}

void ajusteReta(int n, double x[], double y[], double *a, double *b){
    double somaX = 0, somaY = 0, somaX2 = 0, somaXY = 0;

    // calcula os somatórios para o MMQ
    for(int i = 0; i < n; i++){
        somaX  += x[i];               // Σx
        somaY  += y[i];               // Σy
        somaX2 += x[i] * x[i];        // Σx²
        somaXY += x[i] * y[i];        // Σxy
    }

    double determinante = somaX2 * n - somaX * somaX;   // determinante 2x2 para a reta

    *a = (n * somaXY - somaX * somaY) / determinante;  // coeficiente angular
    *b = (somaX2 * somaY - somaX * somaXY) / determinante;  // coeficiente linear

    printf("\nAjuste da reta pelo MMQ:\n");
    printf("a = %.6f\n", *a);
    printf("b = %.6f\n", *b);
}


void ajusteParabola(int n, double x[], double y[], double coef[]){
    double somaX=0, somaX2=0, somaX3=0, somaX4=0;
    double somaY=0, somaXY=0, somaX2Y=0;

    for(int i=0; i<n; i++){
        somaX   += x[i];             // Σx
        somaX2  += x[i]*x[i];       // Σx²
        somaX3  += x[i]*x[i]*x[i];  // Σx³
        somaX4  += x[i]*x[i]*x[i]*x[i]; // Σx^4
        somaY   += y[i];             // Σy
        somaXY  += x[i]*y[i];        // Σxy
        somaX2Y += x[i]*x[i]*y[i];   // Σx²y
    }

    // construir a matriz aumentada 3x4
    double A[3][MAX + 1] = {
        {n,     somaX,   somaX2,  somaY},
        {somaX, somaX2,  somaX3,  somaXY},
        {somaX2,somaX3,  somaX4,  somaX2Y}
    };

    gauss(3, A); // aplica gauss para escalonamento
    substituicao(3, A, coef);  // resolve o sistema para achar os 3 coeficientes


    printf("\nAjuste da parabola pelo MMQ:\n");
    printf("a = %.6f\nb = %.6f\nc = %.6f\n", coef[0], coef[1], coef[2]);
    printf("\nEquacao da parabola final:\n");
    printf("g(x) = %.6fx^2 + %.6fx + %.6f\n", coef[0], coef[1], coef[2]);
}


int main(){
    int n, m;  // n = número de pontos, m = grau do polinômio (1 ou 2)
    double x[100], y[100]; //guarar as coordenadas

    printf("Digite o grau do polinomio: "); 
    printf("\n- 1 (reta)");
    printf("\n- 2 (parabola)\n");
    scanf("%d", &m);

    if(m != 1 && m != 2){
        printf("So pode escolher 1 para reta e 2 para parabola.");
        return 0;
    }
    printf("Digite o numero de pontos: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Digite o ponto %d (x y): ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

        double a, b;

    if(m==1){
        double a,b;  // os coeficientes da reta
        ajusteReta(n, x, y, &a, &b);
        printf("\nEquacao da reta final: g(x) = %.6fx + %.6f\n", a, b);
    } else {
        double coef[3];  // coeficientes da parabola
        ajusteParabola(n, x, y, coef);
    }


}