#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int flag = 0;
int sum = 0;
#define TAM 100

void fill_rand(int *arr) {
    for (int i = 0; i < TAM; i++) {
        arr[i] = rand() % 100;  
    }
}

int sum_array(int *arr) {
    int total = 0;
    for (int i = 0; i < TAM; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int arr[TAM];
    int tmp_flag;
    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            fill_rand(arr); 
            #pragma omp flush  
            #pragma omp atomic write
            flag = 1; 
            #pragma omp flush(flag) 
        }

        #pragma omp section
        {
            while (1){
                #pragma omp flush(flag)
                #pragma omp atomic read
                tmp_flag = flag;
                if (tmp_flag == 1)
                break;
            }

            #pragma omp flush  
            sum = sum_array(arr); 
        }
    }

    printf("La suma del array es: %d\n", sum);

    return 0;
}
