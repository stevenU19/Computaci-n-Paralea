// From https://www.programiz.com/c-programming/c-for-loop 
// Modified by C. Barrios for training purposes 2023
// Simple Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers

#include <stdio.h>
#include <omp.h>

int main()
{
    int num, count, sum = 0;
    double start, end; 
    
    printf("\nSuma de los primeros n numeros naturales\n");
    printf("Ingrese un Entero Positivo: ");
    scanf("%d", &num);
    
    // Se empieza a contabilizar el tiempo
    start = omp_get_wtime();
   
    // pragma: Para paralelizar al ciclo iterativo for
    #pragma omp parallel for reduction(+:sum) 
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
    
    // Se termina de contabilizar el tiempo
    end = omp_get_wtime(); 
    
    printf("Suma Total = %d\n", sum);    
    printf("La ejecucion tardo %lf segundos\n", end - start);
  
    return 0;
}
