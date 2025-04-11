#include<stdio.h>
#include<omp.h>

double big_job(int i) {
    double resultado = 0.0;
    for (int j = 0; j < 1000; j++) {
        resultado += i * 9.0 + j;
    }
    return resultado;
}

double consume(double B) {
    return B + 9.0;
}

int main(){
    int niters = 10;
    double res = 0.0;
    #pragma omp parallel
    {
        double B;
        int i, id, nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for ( i = id ; i < niters ; i += nthrds){
            B = big_job(i);
            #pragma omp critical
            res += consume(B);
        }
        printf("res = %f\n", res);
    }
    return 0;
}


