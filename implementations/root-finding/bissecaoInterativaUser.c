#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float f(float x){
    return (x * x * x) - 5;
}

bool verificarIntervaloBolzano(float a, float b){
    if(f(a) * f(b) >= 0){
        printf("intervalo nao valido para Bolzano!");
        return 0;
    }
    return 1;
}

float bissecao(float a, float b, float tolerancia){
    float fPm;
    float pontoMedio;
    float fA, fB;

    do{
        fA = f(a);
        fB = f(b);
        verificarIntervaloBolzano(a,b);
        
        pontoMedio = (a + b) / 2;
        fPm = f(pontoMedio);

        if(fabs(fPm) <= tolerancia){
            break;
        } if(fA * fPm < 0){
            b = pontoMedio;
        } else {
            a = pontoMedio;
        }
    } while(fabs(fPm) > tolerancia);

    return pontoMedio;
}

int main(){
    float a, b, tolerancia;

    printf("f(x) = x^3 - 5  --> Digite valores para A e B para ENCONTRAR RAIZ:\n");

    printf("valor de 'a':");
    scanf("%f", &a);
    printf("valor de 'b':");
    scanf("%f", &b);
    printf("valor da tolerancia:\n");
    scanf("%f", &tolerancia);

    float raizEncontrada = bissecao(a, b, tolerancia);
    printf("Raiz aproximada encontrada: %.2f\n", raizEncontrada);
}