#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

Complex* criarComplexo(double a, double b) {
    Complex* novoComplexo = (Complex*)malloc(sizeof(Complex));
    if (novoComplexo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }

    novoComplexo->real = a;
    novoComplexo->imag = b;

    return novoComplexo;
}

void liberarComplexo(Complex** numeroComplexo) {
    if (*numeroComplexo != NULL) {
        free(*numeroComplexo);
        *numeroComplexo = NULL;  // Definir o ponteiro como NULL após a liberação
    }
}

Complex* somarComplexos(Complex* num1, Complex* num2) {
    double realSoma = num1->real + num2->real;
    double imagSoma = num1->imag + num2->imag;

    return criarComplexo(realSoma, imagSoma);
}

Complex* subtrairComplexos(Complex* num1, Complex* num2){
    double realSub = num1 -> real - num2-> real;
    double imagSub = num1->imag - num2->imag;

    return criarComplexo(realSub, imagSub);
}

Complex* multiplicaComplexos(Complex* num1, Complex* num2){
    double realMult = (num1->real * num2->real) - (num1->imag * num2->imag);
    double imagMult = (num1->real * num2->imag) + (num1->imag * num2->real);

    return criarComplexo(realMult, imagMult);
}
Complex* divideComplexos(Complex* num1, Complex* num2){
    // Calcule os componentes da divisão de acordo com a fórmula
    double divisor = (num2->real * num2->real) + (num2->imag * num2->imag);
    double realResultado = ((num1->real * num2->real) + (num1->imag * num2->imag)) / divisor;
    double imagResultado = ((num1->imag * num2->real) - (num1->real * num2->imag)) / divisor;

    // Crie e retorne um novo número complexo que representa o resultado da divisão
    return criarComplexo(realResultado, imagResultado);
}

