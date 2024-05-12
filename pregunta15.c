// Estudiante: Ruben Condori Blanco
//pregunta 15

#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) 
{
  // Inicializacion de MPI
  MPI_Init(NULL, NULL);

  int cantidad;
  int procesador;
  MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
  MPI_Comm_rank(MPI_COMM_WORLD, &procesador);

  // conseguir nombre de proceso
  char processor_nombre[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_nombre, &name_len);

  // Imprimir Hola Mundo
  printf("\n\t Hola Mundooo...  del procesador %s, rango %d de %d procesadores\n", processor_nombre, procesador, cantidad);

  // Finalizacion de MPI 
  MPI_Finalize();
}
