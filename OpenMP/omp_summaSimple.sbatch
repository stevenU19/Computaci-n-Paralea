#!/bin/bash
#SBATCH --partition=normal
#SBATCH --job-name=OpenMP
#SBATCH --nodes=1

#SBATCH --ntasks=1  
#SBATCH --cpus-per-task=16
#SBATCH --ntasks-per-node=1
#SBATCH --output=output_summaSimple.txt%j.out
#SBATCH --error=error_summaSimple.err%j.err 

# Cargar Modulos
module load devtools/gcc/6.2.0

## Se compila el archivo "omp_summaSimple.c" y se genera el ejecutable "output_summaSimple"
gcc -fopenmp omp_summaSimple.c -o output_summaSimple

## Ejecucion del programa, ingresando el numero 10 como entrada y exportando la salida a un txt
echo "10" | ./output_summaSimple > output_summaSimple.txt
