//4.Realizar en OPENMP la multiplicacion de una matriz N*N con un vector de dimension N.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int N;
// Función para mostrar matrices
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

// Función principal
void main() 
{
    // Declaración de variables
    int matriz_a[50][50], matriz_b[50][50], matriz_c[50][50];
    int i, j, k, tid, nthreads; 

    srand(time(NULL)); // semilla para generar números aleatorios
    double tinicial, tfinal;
    
    printf("\t\n Introduzca el valor de N: ");
    scanf("%d",&N);
    // Empezar contador de tiempo
    tinicial = omp_get_wtime();

    #pragma omp parallel shared(matriz_a, matriz_b, matriz_c, nthreads) private(tid, i, j, k)
	tid = omp_get_thread_num();
	#pragma omp for
	for (i = 0; i < N; i++) 
	{
	   for (j = 0; j < N; j++)
	   {
		matriz_a[i][j] = rand() % 10;
	   }
	}
	#pragma omp for
	for (i = 0; i < N; i++) 
	{
	   for (j = 0; j < N; j++)
	   {
		matriz_b[i][j] = rand() % 10;
	   }
	}
	#pragma omp for
	for (i = 0; i < N; i++) 
	{
	   for (j = 0; j < N; j++)
	   {
		matriz_c[i][j] = 0;
	   }
	}
	#pragma omp for
	for (i = 0; i < N; i++)
	{
	   for (j = 0; j < N; j++) 
	   {
	      for (k = 0; k < N; k++)
	      {
		 matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
	      }
	   }
	}

	// Imprimir matrices
	printf("\nMatriz A:\n");
	mostrar_matriz(matriz_a,N);
	printf("\nMatriz B:\n");
	mostrar_matriz(matriz_b,N);
	printf("\nMatriz C, Producto de AxB:\n");
	mostrar_matriz(matriz_c,N);
	
        tfinal = omp_get_wtime()-tinicial;
	
	// Imprimir tiempo de ejecución
	printf("\n-------------------\n");
	printf("Tiempo de ejecución del proceso de multiplicacion de AxB (CPU): %f segundos\n",tfinal );

}
