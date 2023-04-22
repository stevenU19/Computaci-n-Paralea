#!/binbash
#SBATCH --partition=guane_24_cores
#SBATCH --job-name=summaSimple
#SBATCH --nodes=3

#SBATCH --mem=23000
#SBATCH --ntasks-per-node=24
#SBATCH --gres=gpu:4
#SBATCH --output=output_summaSimple.txt%j.out
#SBATCH --error=error_summaSimple.txt%j.err 

# Cargar modulos
module load gcc

## Se compila el archivo "omp_summaSimple.c" y se genera el ejecutable "output_summaSimple"
gcc omp_summaSimple.c -o output_summaSimple

## Ejecucion del programa
./output_summaSimple

