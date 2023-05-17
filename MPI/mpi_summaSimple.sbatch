#!/bin/bash
#SBATCH --job-name=MPI
#SBATCH --nodes=2
#SBATCH --ntasks=2 
#SBATCH --cpus-per-task=8

#SBATCH --output=output_summaSimple.txt%j.out
#SBATCH --error=error_summaSimple.err%j.err 

# Cargar Modulos de gcc y mpi
module load devtools/gcc/6.2.0
module load devtools/mpi/openmpi/3.1.4

## Se compilan los archivos "summaSimple.c", "mpi_summaSimple.c", "omp_summaSimple.c" 
gcc summaSimple.c -o summaSimple
gcc -fopenmp omp_summaSimple.c -o omp_summaSimple
mpicc mpi_summaSimple.c -o mpi_summaSimple

## Ejecucion del programa, ingresando el numero 10 como entrada y exportando la salida a un txt
echo "10" | ./summaSimple >>  output_summaSimple.txt
echo "10" | ./omp_summaSimple >>  output_summaSimple.txt
echo "10" | ./mpi_summaSimple >>  output_summaSimple.txt
