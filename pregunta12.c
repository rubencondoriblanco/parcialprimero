//12.Realice el calculo de Fibonacci con MPI mediante un procesador MASTER que solicite cada termino a los procesadores SLAVE.
#include<mpi.h>
#include"math.h"
#include<stdio.h>

int main(int argc, char *argv[])
{
   int procesador, cantidad;
   int i;   
   int N=10,M,j;
   int fibo1[N],fibo2[N],fibo3[N];
    
   MPI_Init(&argc, &argv);
   
   MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
   MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
   printf("\n\t Hola Mundooo... \n  procesador %d cantidad %d \n", procesador, cantidad);
   
   
   if(procesador == 1)
   {
      fibo1[0] = 0;
      fibo1[1] = 1;
      for(i=2;i<N;i++)
      {
         fibo1[i] = fibo1[i-1] + fibo1[i-2];
      }
      MPI_Send(fibo1,N,MPI_INT,0,0,MPI_COMM_WORLD);    
   }
   if(procesador == 2)
   {
      fibo2[0] = ((1/sqrt(5))*pow((1+sqrt(5))/2,N))-((1/sqrt(5))*pow((1-sqrt(5))/2,N));
      fibo2[1] = ((1/sqrt(5))*pow((1+sqrt(5))/2,(N+1)))-((1/sqrt(5))*pow((1-sqrt(5))/2,(N+1)));
      for(i=2;i<N;i++)
      {
         fibo2[i] = fibo2[i-1] + fibo2[i-2];
      }
      MPI_Send(fibo2,N,MPI_INT,0,0,MPI_COMM_WORLD);    
   }
   
   if(procesador == 3)
   {
      fibo3[0] = ((1/sqrt(5))*pow((1+sqrt(5))/2,N*2))-((1/sqrt(5))*pow((1-sqrt(5))/2,N*2));
      fibo3[1] = ((1/sqrt(5))*pow((1+sqrt(5))/2,(N*2+1)))-((1/sqrt(5))*pow((1-sqrt(5))/2,(N*2+1)));
      for(i=2;i<N;i++)
      {
         fibo3[i] = fibo3[i-1] + fibo3[i-2];
      }
      MPI_Send(fibo3,N,MPI_INT,0,0,MPI_COMM_WORLD);    
   }
   
   if(procesador == 0)
   {
      MPI_Recv(fibo1,N,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      MPI_Recv(fibo2,N,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      MPI_Recv(fibo3,N,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      for(i=0;i<N;i++)printf("%d ,",fibo1[i]);
      for(i=0;i<N;i++)printf("%d ,",fibo2[i]);
      for(i=0;i<N;i++)printf("%d ,",fibo3[i]);
      printf("\n ,");
   }
   MPI_Finalize();
}
