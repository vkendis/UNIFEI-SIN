typedef struct {
    double real;
    double imag;
} Complex;

Complex* criarComplexo(double a, double b);
void liberarComplexo(Complex** numeroComplexo);
Complex* somarComplexos(Complex* num1, Complex* num2);
Complex* subtrairComplexos(Complex* num1, Complex* num2);
Complex* multiplicaComplexos(Complex* num1, Complex* num2);
Complex* divideComplexos(Complex* num1, Complex* num2);