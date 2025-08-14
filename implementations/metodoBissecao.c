#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float fX(float x){
    return (x * x) - 2;
}

float pontoMedio(float a, float b){
    return (a + b) / 2;
}


int main(){
    float a = 0;
    float b = 3;
    float tolerancia = 0.05;
    
    float fA;
    float fB;
    float fPm;
    float pontoMedioAtual;

    printf("Inicio: a = %.0f  b = %.0f\n", a, b);
    pontoMedioAtual = pontoMedio(a, b);

    do{
        fA = fX(a);
        fB = fX(b);

        printf("\n Nova Iteracao \n");
        printf("a = %.0f  b = %.0f  fA = %.2f  fB = %.2f\n", a, b, fA, fB);

        if(fA * fB < 0){
            pontoMedioAtual = pontoMedio(a,b);
            fPm = fX(pontoMedioAtual);

            printf("pontoMedioAtual = %.2f  fPm = %.2f\n", pontoMedioAtual, fPm);
            printf("fX(pontoMedioAtual) = %.2f\n", fPm);

            if(fabs(fPm <= tolerancia)){
                printf("Raiz aproximada encontrada: %.2f\n", pontoMedioAtual);
                break; 
            } else if(fA * fPm < 0){
                printf("Escolhendo subintervalo: [a, Pm]\n");
                a = a;
                b = pontoMedioAtual;
            } else{
                printf("Escolhendo subintervalo: [Pm, b]\n");
                a = pontoMedioAtual;
                b = b;
            }
        }
    }while(fabs(fX(pontoMedioAtual)) > tolerancia);
}