#include <stdio.h>
#include <math.h>

double funcao(double x){
    return x * x;
}


double simpson13(double a, double b, double h, int n){
    double soma = funcao(a) + funcao(b);
    double xi;

    printf("\nprimeiro ponto x0 = %.4f  f(x0) = %.4f\n", a, funcao(a));

    // pontos internos (x1 até x_{n-1})
    for(int i = 1; i < n; i++){
        xi = a + i * h;    // calcula o xi


        if(i % 2 == 1){ // se for impar soma com peso 4
            soma += 4 * funcao(xi);
        } else {  // se for par soma com peso 2
            soma += 2 * funcao(xi);     
        }
    }

    printf("\nultimo ponto xn:    x%d = %.4f     f(x%d) = %.4f\n", n, b, n, funcao(b));

    // formula regra do simpson 1/3
    double resultadoArea = ( h / 3.0 ) * soma;
    return resultadoArea;
}


int main(){ 
    double a = 0, b = 3.14159265359;    // intervalo [ a, b]   a = limite inferior   b = limite superior
    int n = 1000;             // numero de subintervalos

    if(n % 2 != 0){
        printf("deu ruim, o n deve ser par!\n");
        return 0;
    }
    
    double h = (b - a) / n;

    printf("\nintervalo de integracao: [%.0f, %.0f]\n", a, b);
    printf("n (numero de subintervalos) = %d\n", n);
    printf("h (tamanho de cada subintervalo, a largura) = %.4f\n", h);
    
    double resposta = simpson13(a, b, h, n);
    
    printf("\nresultado da aproximacao pela Regra de Simpson 1/3 resultou em: %.12f\n", resposta);

}