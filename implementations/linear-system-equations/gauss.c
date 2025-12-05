#include <stdio.h>
#include <math.h>

#define MAX 100

void trocaLinha(double A[][MAX + 1], int linha1, int linha2, int n) {  //chamada quando o pivo == 0 
    for (int k = 0; k < n + 1; k++) {
        double temp = A[linha1][k]; // guarda temporariamente o valor da posição (linha 1, coluna k)
        A[linha1][k] = A[linha2][k];  // copia o valor da linha 2 para a linha 1
        A[linha2][k] = temp; // copia o valor antigo da linha 1 (que ta na variavel temp) direto para linha 2   
    }
}

void gauss(int n, double A[][MAX + 1]){
    for(int colunaJ = 0; colunaJ < n - 1; colunaJ++){

        // pivoteamento (troca de linhas com pivo == 0)
        if(A[colunaJ][colunaJ] == 0){
            for(int i = colunaJ + 1; i < n; i++){
                if(A[i][colunaJ] != 0){
                    printf("\nTROCA: L%d <-> L%d (pivo zero)\n", colunaJ, i);
                    trocaLinha(A, colunaJ, i, n);
                    break;
                }
            }
        }

        // parte da eliminação
        for(int linhaI = colunaJ + 1; linhaI < n; linhaI++){
            if(A[linhaI][colunaJ] != 0){ // ver se elemento é zero
                printf("\n");
                if(linhaI != colunaJ){ // não pode ser elemento da diagonal
                    
                double multiplicador = A[linhaI][colunaJ] / A[colunaJ][colunaJ];
                printf("multiplicador da linha m[%d][%d] = %.2f\n", linhaI, colunaJ, multiplicador);

                    for(int k = 0; k < n + 1; k++){
                        printf("operacao: l[%d] <-> l[%d] - %.2f (multiplicador) * l[%d]\n", linhaI, linhaI, multiplicador, colunaJ );
                        A[linhaI][k] = A[linhaI][k] - ( multiplicador * A[colunaJ][k] );
                    }
                }
            }
        }
    }
}


void resolucaoDoSistema(int n, double A[][MAX + 1]){
    double x[n];
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];   // calcula a ultima linha por que só tem uma variavel

    for(int i = n - 2; i >= 0; i--){
        double resultado = 0.0;   // soma os termos da linha i

        for(int j = i + 1; j < n; j++){  // soma os produtos ja calculados pelos itens da linha
            resultado += x[j] * A[i][j];   // ∑ de j=i+1 até N  ->  Xj * Aij
        }   

        x[i] = ( A[i][n] - resultado ) / A[i][i];  // isolar x[i] da equação, x[i] = (b - soma dos outros termos) / coeficiente da diagonal
    }

    printf("Solucao para x1, x2, x3 eh:\n");
    for(int k = 0; k < n; k++){
        printf("x[%d] = %.2f\n", k + 1, x[k]);
    }
}