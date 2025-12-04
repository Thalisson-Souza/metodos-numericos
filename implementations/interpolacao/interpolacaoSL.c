#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../linear-system-equations/gauss.h"

#define MAX 10

void matrizAumentada(double A[MAX][MAX], double x[], double y[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = pow(x[i], n - 1 - j);
        }
        A[i][n] = y[i];
    }
}


void mostrarMatriz(double A[MAX][MAX], int n){
    printf("Matriz Aumentada:\n");
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
    int grauPolinomio;

    grauPolinomio = n - 1;

    double A[MAX][MAX];

    matrizAumentada(A, x, y, n);

    printf("Matriz aumentada inicial:\n");
    mostrarMatriz(A, n);
    

    gauss(n, A);

    printf("Depois da eliminacao de Gauss:\n");
    mostrarMatriz(A, n);

    resolucaoDoSistema(n, A);


}