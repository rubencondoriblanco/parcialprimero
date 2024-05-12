// Estudiante: Ruben Condori Blanco
// Pregunta 6
//6. en MPI realizar el calculo de PI.
#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
   int procesador, cantidad;
   int i, j ;   

   double pi;
   MPI_Init(&argc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
   MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
   printf("\n\t  procesador %d cantidad %d \n", procesador, cantidad);

   for( i=0 ; i<cantidad ; i++ )
   { 
     
      if(procesador == i)
      {
         int n=100000000;
         double tinicial, tfinal;
         double h = 1.0 / (double) n;
         double sum = 0.0; 
         double x;
         tinicial = MPI_Wtime();
         for ( j = 1 ; j <= n ; j++ )
         {
            x = h*((double)j-0.5);
            sum = sum + (4.0 /(1.0 + x*x));
         }
      
         pi = sum*h;
 
         tfinal = MPI_Wtime()-tinicial;
         printf("\t Procesador %d ", i);
         printf("\t Cantidad de tiempo: %f ", tfinal );
         printf("\t Calculo de Pi: %f \n", pi );
      }
   } 

   printf("\n");
   MPI_Finalize();
}
