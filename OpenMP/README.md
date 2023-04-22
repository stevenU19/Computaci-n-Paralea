## Primer Taller
La carpeta se compone de 6 archivos los cuales summaSimple.c es el archivo original, omp_summaSimple.c es el archivo paralelizado, output_summaSimple el programa compilado, output_summaSimple.txt el registro de las salidas y omp_summaSimple.sbatch, el archivo sbatch con la ejecución del programa.

Usando una compilación con gcc, el programa se le agrega la librería omp.h para usar OpenMP y el comando #pragma omp parallel for reduction(+:sum) para paralelizar el ciclo iterativo for. La variable sum se declara con una reducción, que garantiza que se combine correctamente el resultado parcial de cada iteración al final del bucle. 
Por último, se contabiliza el tiempo de ejecución, que comprende el antes y después del ciclo for.
