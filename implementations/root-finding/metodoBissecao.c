#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double f(double x){
    return (x * x) - 2;
}

double pontoMedio(double a, double b){
    return (a + b) / 2;
}

bool bolzano(double a, double b){
    return f(a) * f(b) < 0;
}

int main(){
    double a = 0;
    double b = 3;
    double tolerancia = 0.05;

    if(!bolzano(a, b)){
        printf("intervalo deu ruim ai!, f(a) e f(b) tem mesmo sinal!");
        return 0;
    }

    double fA, fB, fPm, pontoMedioAtual;
    int interacoes = 0;

    printf("Inicio: a = %.0f  b = %.0f\n", a, b);

    do{
        interacoes++;
        fA = f(a);
        fB = f(b);

        pontoMedioAtual = pontoMedio(a, b);
        fPm = f(pontoMedioAtual);

        printf("\n Nova Iteracao\n");
        printf("a = %.0f  b = %.0f  fA = %.2f  fB = %.2f\n", a, b, fA, fB);

        if(fabs(fPm) <= tolerancia){
            printf("\nConvergencia pela IMAGEM -> raiz aproximada: %.4f\n", pontoMedioAtual);
            break;
        }

        if(fA * fPm < 0){
            b = pontoMedioAtual; // raiz está em [a, m]
        } else {
            a = pontoMedioAtual; // raiz está em [m, b]
        }

        if(fabs(b - a) <= tolerancia){
            printf("\nConvergencia pelo DOMINIO -> raiz aproximada: %.4f\n", pontoMedioAtual);
            break;
        }

    }while(true);
}