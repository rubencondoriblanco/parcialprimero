// Programación paralela de la multiplicación de matrices: MPI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

// Función para multiplicar matrices

void multiplicar_matrices(int matriz_a[50][50], int matriz_b[50][50], int matriz_c[50][50], int M)
{
   int i, j, k;
   for (i = 0; i < M; i++) 
   {
      for (j = 0; j < M; j++) 
      {
	 matriz_c[i][j] = 0;
	 for (k = 0; k < M; k++)
         {
	    matriz_c[i][j] =  matriz_c[i][j] + matriz_a[i][k] * matriz_b[k][j];
	 }
      }
   }	
}

// Función para imprimir matrices

void mostrar_matriz(int matriz[50][50],int M)
{
	int i, j;
	for (i = 0; i < M; i++) 
	{
	   printf("\t");
	   for (j = 0; j < M; j++) 
	   {
		printf("%d ", matriz[i][j]);
	   }
		printf("\n");
	}
	printf("\n");
}

// Función para rellenar matrices
void rellenar_matriz(int matriz[50][50],int M)
{
   int i, j;
   for (i = 0; i < M; i++)
   {
      for (j = 0; j < M; j++) 
      {
	 matriz[i][j] = rand() % 10;
      }
   }
}

// Función principal
int main(int argc, char *argv[]) 
{
	// Declaración de variables
   int rank, size;
   int n = 3;
    double tinicial, tfinal;
   // Inicializar MPI
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
  
   // Declaración de variables
   int matrix_a[50][50], matrix_b[50][50], matrix_c[50][50];
   tinicial = MPI_Wtime();
   srand(time(NULL)); // semilla para generar números aleatorios

   if (rank == 0) 
   {
	// Llenar las matrices A y B solo en el proceso 0
	rellenar_matriz(matrix_a,n);
	rellenar_matriz(matrix_b,n);

	printf("\nMatriz A:\n");
	mostrar_matriz(matrix_a,n);

	printf("\nMatriz B:\n");
	mostrar_matriz(matrix_b,n);
   }

   // Transmitir las matrices A y B a todos los procesos
   MPI_Bcast(&matrix_a[0][0], n * n, MPI_INT, 0, MPI_COMM_WORLD);
   MPI_Bcast(&matrix_b[0][0], n * n, MPI_INT, 0, MPI_COMM_WORLD);

   // Multiplicación de matrices
   multiplicar_matrices(matrix_a, matrix_b, matrix_c,n);

   // Recopilar resultados en el proceso 0
   MPI_Gather(&matrix_c[0][0], n * n, MPI_INT, &matrix_c[0][0], n * n, MPI_INT, 0, MPI_COMM_WORLD);

   if (rank == 0) 
   {
      printf("\nMatriz C (resultado) AxB:\n");
      mostrar_matriz(matrix_c,n);
   }
   tfinal = MPI_Wtime()-tinicial;
   // Imprimir tiempo de ejecución
   printf("\t-------------------\n");
   printf("\tProceso %d de %d\n", rank, size);
   printf("\tTiempo de ejecución del programa (CPU): %f segundos\n", tfinal);

   // Finalizar MPI
   MPI_Finalize();

   // Fin del programa
   return 0;
}
