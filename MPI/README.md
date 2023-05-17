## Segundo Taller - Wilmer Farfán 2194285
La carpeta se compone de 5 archivos los cuales consisten en summaSimple.c como el archivo original, mpi_summaSimple.c es el archivo paralelizado con MPI, output_summaSimple.txt el registro de las salidas y la comparación en tiempos y omp_summaSimple.sbatch, el archivo sbatch con la ejecución del programa completo.

Usando una compilación con mpi, el programa se le agrega la librería mpi.h para usar MPI y los siguientes comandos:
- **MPI_Init(&argc, &argv):** Se inicializa MPI.
- **MPI_Comm_rank(MPI_COMM_WORLD, &rank):** Se obtiene el tamaño del rango.
- **MPI_Comm_size(MPI_COMM_WORLD, &size):** Se obtiene el tamaño del comunicador.
- **MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD):** Es una función que tiene como objetivo facilitar el acceso al valor del número *num*, desde el proceso número cero hasta los demás procesos del comunicador MPI_COMM_WORLD.
- **MPI_Reduce(&local_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD):** Reduce el valor de la variable *local_sum* para obtener la suma total de todos los procesos.

De esta manera se paraleliza el ciclo iterativo for. Por último, se contabiliza el tiempo de ejecución, que toma el correr el programa compilado con MPI. El proceso de rank=0, funciona como un controlador para que no se ejecute el número de veces que corresponden a los procesadores de la máquina.

Para este caso se aprecia la diferencia entre los tiempos presentes en el archivo output_summaSimple.txt, los cuales difieren. Para este caso en particular, con el OpenMP se tiene un tiempo mucho menor respecto al compilado en MPI, lo cual lo hace mucho más rápido en la ejecución del programa.
