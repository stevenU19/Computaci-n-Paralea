// From https://www.programiz.com/c-programming/c-for-loop 
// Modified by Wilmer Farfan for learning purposes 2023
// Simple Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers

#include <stdio.h>
#include <time.h>

int main()
{
    int num, count, sum = 0;
    
    // Contabilizar el tiempo    
    clock_t startTime, endTime;
  
    // Se empieza a contabilizar el tiempo
    startTime = clock();
    
    printf("\nSuma de los primeros n numeros naturales (Sin Paralelizar)\n");
    printf("Ingrese un Entero Positivo: ");
    scanf("%d", &num); 

    // for loop terminates when num is less than count
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
    
    // Se termina de contabilizar el tiempo
    endTime = clock(); 

    printf("Suma Total = %d\n", sum);    
    printf("La ejecucion tardo %lf segundos\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}
