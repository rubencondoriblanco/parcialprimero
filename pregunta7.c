// Estudiante:Ruben Condori Blanco
#include <stdio.h>
#include "omp.h"

void main()
{
    int activo, cantidad, i;
    #pragma omp parallel
    cantidad=omp_get_num_threads();
    printf("cantidad de hilos %d \n \n", cantidad);
    
    for( i = 0 ; i < cantidad ; i++ )
    {
      omp_set_num_threads(i); 
      double tinicial, tfinal;
      int j, n=100000000;
      tinicial = omp_get_wtime();
      double h = 1.0 / (double) n;
      double sum = 0.0; 
      double x, pi;
      #pragma omp parallel shared(sum)
      {
         #pragma omp for reduction(+:sum)
         for ( j = 1 ; j <= n ; j++ )
         {
            x = h*((double)j-0.5);
            sum += (4.0 /(1.0 + x*x));
         }
      }
      pi = sum*h;
      tfinal = omp_get_wtime()-tinicial;

      printf("\t Procesador %d ", i);
      printf("\t Cantidad de tiempo: %f ", tfinal );
      printf("\t Calculo de Pi: %f \n", pi );
    }
}
