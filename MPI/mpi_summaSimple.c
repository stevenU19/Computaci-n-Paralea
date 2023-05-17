// From https://www.programiz.com/c-programming/c-for-loop 
// Modified by Wilmer Farfan for learning purposes 2023
// Simple Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int num, count, sum = 0;
    int rank, size, local_sum = 0;
    double startTime, endTime;
    

    // Se empieza a contabilizar el tiempo
    startTime = MPI_Wtime();

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if (rank == 0) {
        printf("\nSuma de los primeros n numeros naturales (Paralelizado con MPI)\n");
        printf("\nIngrese un Entero Positivo: \n");
        scanf("%d", &num);
    }
    
    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int start = (num / size) * rank + 1;
    int end = (num / size) * (rank + 1);

    if (rank == size - 1) {
        end = num;
    }

    for (count = start; count <= end; ++count) {
        local_sum += count;
    }

    MPI_Reduce(&local_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Suma Total = %d\n", sum);
        
        // Se termina de contabilizar el tiempo
        endTime = MPI_Wtime();        
        printf("La ejecucion tardo %lf segundos\n", endTime - startTime); 
    }

    MPI_Finalize();

    // Se termina de contabilizar el tiempo
    endTime = MPI_Wtime(); 
    
    return 0;
}