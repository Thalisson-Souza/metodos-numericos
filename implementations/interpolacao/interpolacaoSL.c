#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../linear-system-equations/gauss.h"

// gcc interpolacao/interpolacaoSL.c linear-system-equations/gauss.c -o interpolacao -lm
// ./in

#define MAX 100

void matrizAumentada(double A[MAX + 1][MAX + 1], double x[], double y[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = pow(x[i], n - 1 - j);
        }
        A[i][n] = y[i];
    }
}


void mostrarMatriz(double A[MAX + 1][MAX + 1], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            printf("%8.3lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){

    int n = 3;  // variavel pro numero de pontos
    double x[3] = {-1, 0, 2};
    double y[3] = {4, 1, -1};
    int grauPolinomio = n - 1;

    double A[MAX + 1][MAX + 1];

    matrizAumentada(A, x, y, n);

    printf("Matriz aumentada inicial:\n");
    mostrarMatriz(A, n);
    
    printf("chamando funcao de eliminacao de Gauss...\n");
    gauss(n, A);

    printf("\nDepois da eliminacao de Gauss:\n");
    mostrarMatriz(A, n);

    resolucaoDoSistema(n, A);


}