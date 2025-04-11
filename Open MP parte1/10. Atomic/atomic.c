#include<stdio.h>
#include<omp.h>

double getNumber() {
    return 9.0;
}

double funcBig(int i) {
    double resultado = 0.0;
    for (int j = 0; j < 1000; j++) {
        resultado += i * 9.0 + j;
    }
    return resultado;
}

int main(){
    double A = 0.0;
    #pragma omp parallel
    {
        double tmp, B;
        B = getNumber();
        tmp = funcBig(B);
        #pragma omp atomic
        A += tmp;
    }
    printf("A = %f\n", A);
    return 0;
}
