#include <stdio.h>
#include "complex.h"

int main() {

    //Criar um numero real utilizando alocacao dinamica ✅
    //Liberar todas as memorias ao fim depois de verificacao NULL ✅
    //Funcao de somar numeros complexos ✅
    //Funcao de subtrair numeros complexos ✅
    //Funcao de multiplicar numeros complexos ✅
    //Funcao de dividir numeros complexos ✅
    
    double a, b, c, d;

    // Solicite ao usuário que insira os valores para a, b, c e d
    printf("Digite a parte real do numero 1: ");
    scanf("%lf", &a);

    printf("Digite a parte imaginária do numero 1: ");
    scanf("%lf", &b);

    printf("Digite a parte real do numero 2: ");
    scanf("%lf", &c);

    printf("Digite a parte imaginária do numero 2: ");
    scanf("%lf", &d);

    printf("\n\n");
    
    // Crie dois números complexos com base nos valores lidos
    Complex* numeroComplexo1 = criarComplexo(a, b);
    Complex* numeroComplexo2 = criarComplexo(c, d);

    printf("******Numeros comples criados 1 e 2: *****\n");
    
    // Exiba os números complexos
    printf("Número complexo 1: %.2lf + %.2lfi\n", numeroComplexo1->real, numeroComplexo1->imag);
    printf("Número complexo 2: %.2lf + %.2lfi\n", numeroComplexo2->real, numeroComplexo2->imag);
    printf("\n\n");
    printf("******Soma dos numeros complexos: *****\n");
    
    // Somar os números complexos
    Complex* resultadoSoma = somarComplexos(numeroComplexo1, numeroComplexo2);
    printf("Resultado da soma: %.2lf + %.2lfi\n", resultadoSoma->real, resultadoSoma->imag);

    printf("\n\n");
    printf("******Subtracao dos numeros complexos: *****\n");
    
    //Subtrair os numeros complexos
    Complex* resultadoSub = subtrairComplexos(numeroComplexo1,numeroComplexo2);
    printf("Resultado da subtracao: %.2lf + %.2lfi\n", resultadoSub->real, resultadoSub->imag);

    printf("\n\n");
    printf("******Multiplicacao dos numeros complexos: *****\n");
    
    //Multiplicar os numeros complexos
    Complex* resultadoMult = multiplicaComplexos(numeroComplexo1,numeroComplexo2);
    printf("Resultado da Multiplicacao: %.2lf + %.2lfi\n", resultadoMult->real, resultadoMult->imag);

    printf("\n\n");
    printf("******Divisao dos numeros complexos: *****\n");
    
    //Dividir os numeros complexos
    Complex* resultadoDiv = divideComplexos(numeroComplexo1,numeroComplexo2);
    printf("Resultado da Divisao: %.2lf + %.2lfi\n", resultadoDiv->real, resultadoDiv->imag);
    printf("\n\n");
    printf("******Liberacao das memorias: *****\n");
    
    // Libere a memória alocada para cada número complexo usando a função
    liberarComplexo(&numeroComplexo1);
    liberarComplexo(&numeroComplexo2);
    liberarComplexo(&resultadoSoma);
    liberarComplexo(&resultadoSub);
    liberarComplexo(&resultadoMult);
    liberarComplexo(&resultadoDiv);
    
 // Verifique se os ponteiros foram definidos como NULL após a liberação
    
    if (numeroComplexo1 == NULL && numeroComplexo2 == NULL && resultadoSoma == NULL && resultadoSub == NULL && resultadoMult == NULL) {
        printf("Memórias liberadas com sucesso.\n");
    } else {
        printf("Erro ao liberar memória.\n");
    }

    return 0;
}