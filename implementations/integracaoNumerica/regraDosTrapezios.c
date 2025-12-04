#include <stdio.h>
#include <math.h>

double funcao(double x){
    return  x * x;
}

double regraDosTrapezio(double a, double b, double h, int n){
    double soma = funcao(a) + funcao(b);
    double xi;

    printf("\nprimeiro ponto x0 = %.4f  f(x0) = %.4f\n", a, funcao(a));

    // pontos internos (x1 até x_{n-1})
    for(int i = 1; i < n; i++){
        xi = a + i * h;    // calcula o xi
        soma += 2 * funcao(xi);    // soma com peso 2
    }

    printf("\nultimo ponto xn:    x%d = %.4f     f(x%d) = %.4f\n", n, b, n, funcao(b));

    // formula regra dos trapézios
    double resultadoArea = ( h / 2.0 ) * soma;
    return resultadoArea;
}


int main(){ 
    double a = 2, b = 3;    // intervalo [ a, b]   a = limite inferior   b = limite superior
    int n = 10;             // numero de subintervalos

    double h = (b - a) / n;

    printf("\nintervalo de integracao: [%.0f, %.0f]\n", a, b);
    printf("n (numero de subintervalos) = %d\n", n);
    printf("h (tamanho de cada subintervalo, a largura) = %.4f\n", h);
    
    double resposta = regraDosTrapezio(a, b, h, n);
    
    printf("\nresultado da aproximacao da integral resultou em: %.12f\n", resposta);

}