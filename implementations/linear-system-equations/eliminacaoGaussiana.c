#include <stdio.h>
#include <stdbool.h>

#define N 3

void printMatriz(int linhas, int colunas, double matrizAumentada[linhas][colunas]){
    for(int linhaI = 0; linhaI < linhas; linhaI++){
        for(int colunaJ = 0; colunaJ < colunas; colunaJ++){
            printf("%.2f ", matrizAumentada[linhaI][colunaJ]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(double matrizAumentada[N][N + 1]){
    for(int colunaJ = 0; colunaJ < N - 1; colunaJ++){
        for(int linhaI = colunaJ + 1; linhaI < N; linhaI++){
            if(matrizAumentada[linhaI][colunaJ] != 0){ // ver se elemento é zero
                printf("\n");
                if(linhaI != colunaJ){ // não pode ser elemento da diagonal
                    
                double multiplicador = matrizAumentada[linhaI][colunaJ] / matrizAumentada[colunaJ][colunaJ];
                printf("multiplicador da linha m[%d][%d] = %.2f\n", linhaI, colunaJ, multiplicador);

                    for(int k = 0; k < N + 1; k++){
                        printf("operacao: l[%d] <-> l[%d] - %.2f (multiplicador) * l[%d]\n", linhaI, linhaI, multiplicador, colunaJ );
                        matrizAumentada[linhaI][k] = matrizAumentada[linhaI][k] - ( multiplicador * matrizAumentada[colunaJ][k] );
                    }
                }
            }
        }
    }
}

void montarMatrizAumentada(double matrizAxb[N][N+1], double matrizA[N][N], int vetorB[N]){
    for(int i = 0; i <  N; i++){
        for (int j = 0; j < N; j++){
            matrizAxb[i][j] = matrizA[i][j];
        }
        matrizAxb[i][N] = vetorB[i];
    }
}

int main(){

    double matrizA[N][N] = {
        {3, 2, 4}, 
        {1, 1, 2},
        {4, 3, -2}
    };

    int vetorB[N] = { 1, 2, 3};
    double matrizAumentada[N][N + 1];

    printf("Matriz A:\n");
    printMatriz(N, N, matrizA);

    printf("Vetor B:\n");
    for(int i = 0; i < N; i++){
        printf("%d\n", vetorB[i]);
    }

    montarMatrizAumentada(matrizAumentada, matrizA, vetorB);

    gaussJordan(matrizAumentada);

    printf("\n");

    printf("Matriz Aumentada apos eliminacao Gauss:\n");
    printMatriz(N, N + 1, matrizAumentada);

    return 0;
}