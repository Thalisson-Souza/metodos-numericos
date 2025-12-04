#include <stdio.h>

void gauss(int n, double matrizAumentadaA[n][n + 1]){
    for(int colunaJ = 0; colunaJ < n - 1; colunaJ++){
        for(int linhaI = colunaJ + 1; linhaI < n; linhaI++){
            if(matrizAumentadaA[linhaI][colunaJ] != 0){ // ver se elemento é zero
                printf("\n");
                if(linhaI != colunaJ){ // não pode ser elemento da diagonal
                    
                double multiplicador = matrizAumentadaA[linhaI][colunaJ] / matrizAumentadaA[colunaJ][colunaJ];
                printf("multiplicador da linha m[%d][%d] = %.2f\n", linhaI, colunaJ, multiplicador);

                    for(int k = 0; k < n + 1; k++){
                        printf("operacao: l[%d] <-> l[%d] - %.2f (multiplicador) * l[%d]\n", linhaI, linhaI, multiplicador, colunaJ );
                        matrizAumentadaA[linhaI][k] = matrizAumentadaA[linhaI][k] - ( multiplicador * matrizAumentadaA[colunaJ][k] );
                    }
                }
            }
        }
    }
}


void resolucaoDoSistema(int n, double matrizAumentadaA[n][n+1]){
    double x[n];
    x[n - 1] = matrizAumentadaA[n - 1][n] / matrizAumentadaA[n - 1][n - 1];

    for(int i = n - 2; i >= 0; i--){
        int resultado = 0;

        for(int j = i + 1; j < n; j++){
            resultado += x[j] * matrizAumentadaA[i][j];   // ∑ de j=i+1 até N  ->  Xj * Aij
        }   

        x[i] = ( matrizAumentadaA[i][n] - resultado ) / matrizAumentadaA[i][i];
    }

    printf("Solucao para x1, x2, x3 eh:\n");
    for(int k = 0; k < n; k++){
        printf("x[%d] = %.0f\n", k + 1, x[k]);
    }
}