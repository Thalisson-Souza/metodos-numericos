#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 3

void GaussJacobi(double A[N][N], double vetorB[N], double x[N], double epsilon, int n_max, double C[N][N], double G[N]){
    double novoX[N]; // declaração para o novo valor do x^( k + 1)

    // construção da matriz C e vetor G
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                C[i][j] = 0;    // diagonal principal zerada
            } else{
                C[i][j] = -A[i][j] / A[i][i];   
            }
        }
        G[i] = vetorB[i] / A[i][i];   
    }

    // Mostrar Vetor G dps de construido
    printf("\nVetor G:\n");
    for(int i = 0; i < N; i++){
        printf("G[%d] = %.1f\n", i, G[i]);
    }

    // Mostrar Matriz C dps de construida
    printf("\nMatriz C:\n"); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("C[%d][%d] = %.1f  ", i, j, C[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    // Teste de convergencia: Tolerância  | C | <  1    (norma da matriz é < 1)
    double somalinha[N] = {0};  // guardar soma do valores absolutos de cada linha da matriz C
    double normaMax = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("C[%d][%d] = %.2f\n",i, j, C[i][j]);
            somalinha[i] += fabs(C[i][j]);  // soma os modulos dos itens da linha i
        }
        printf("soma da linha = %.2f\n", somalinha[i]);
        
        if(somalinha[i] > normaMax) normaMax = somalinha[i]; //pega o maior valor das somas das linhas, para guardar em normaMax
    }

    printf("\na norma maxima eh: %.2f\n", normaMax);
    // Teste final se a convergencia é valida se a norma max  < 1
    if(normaMax < 1){
        printf("como a norma maxima acima eh < 1, por isso o metodo Gauss-Jacobi tende a convergir\n");
    }else{
        printf("como a norma maxima acima eh > 1, por isso o metodo Gauss-Jacobi pode NAO convergir\n");
        return; //como a norma > 1, já nao deixa ir para as iterações
    }


    // aplicar iterações do gauss jacobi
    bool convergiu = false;
    for(int k = 1; k < n_max; k++){

        // calcular novoX     x^(k+1) = C * x^(k) + G
        for(int i = 0; i < N; i++){
            novoX[i] = G[i]; // chute inicial que comeca com G
            for(int j = 0; j < N; j++){
                novoX[i] += C[i][j] * x[j];    // variavel novoX[i] -> é o x^(1)
            }
        }


        // calculo do erro
        double erro = 0;
        double numerador = 0, denominador = 0;
        for(int i = 0; i < N; i++){
            double diferenca = fabs(novoX[i] - x[i]);
            if(diferenca > numerador) numerador = diferenca;
        }
        for(int i = 0; i < N; i++){
            double valor = fabs(novoX[i]);
            if(valor > denominador) denominador = valor;
        }


        // calculo final do erro
        erro = numerador / denominador;


        printf("\n iteracao %d\n", k);
        if(erro < epsilon){
            printf("erro relativo = %.6f < , CONVERGENCIA VALIDA!!!!", erro);
            convergiu = true;
            break;
        }else{
            printf("erro relativo = %.6f > epsilon, segue sem convergir ainda\n", erro);
        }

        // atualiza o valor x
        for(int i = 0; i < N; i++){
            x[i] = novoX[i];
        }
    }

    if(!convergiu) printf("\nNAO CONVERGIU -> estouro do N_MAX de iteracoes (%d)\n", n_max);

    // exibir solução aproximada
    printf("\n\n solucao aproximada final:\n");
        for(int i = 0; i < N; i++){
            printf("x[%d] = %.6f\n", i, x[i]);
        }

}


int main(){

    //Entradas:
        // A = matriz do problema (coeficientes)
        // b = vetor
        // X0 = vetor de estimativa inicial (para poder achar o prox)
        // epsilon = tolerancia (precição)
        // N_MAX = numero maximo de iterações

    //Construir 
        // c -> matriz de iteração
        // vetor g

    double a[N][N] = {
        {10, 2, 1}, 
        {1, 5, 1},
        {2, 3, 10}
    }; 
    double vetorB[N] = {7, -8, 6};
    double x[N] = {0.7, -1.6, 0.6};   
    double epsilon = 0.07;
    double n_max = 10;
     
    double c[N][N];
    double g[N];

    GaussJacobi(a,vetorB, x, epsilon, n_max, c, g);

    return 0;
}