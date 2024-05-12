
//9. Genere la serie 2,4,6,8,10,12,14,16,18… en M vectores(procesadores) para N  terminos con MPI.
#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
   int procesador, cantidad;
   int i, j, par;   
   int N, M, O;
   
   MPI_Init(&argc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
   MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
   printf("\n\t  procesador %d cantidad %d \n", procesador, cantidad);
   printf("\t\t Genere la serie 2,4,6,8,10,12,14,16,18... N: ");
   printf("\t\n en M vectores(procesadores) para N  terminos con MPI.\n Introduzaca N:");

   printf("\n");
   scanf("%d",&N);
   M = N / cantidad;
   O = N % cantidad;
   par = 2;
   for( i=0 ; i<cantidad ; i++ )
   { 
      if(procesador == i)
      {
         for( j=0 ; j<M ; j++)
         {
            printf("%d, ",par);
            par = par + 2;
         }
      }
   } 

   printf("\n");
   MPI_Finalize();
}
