// Estudiante: Ruben Condori Blanco
// Pregunta 1 
#include <stdio.h>

void main()
{ 
   float *a, *b;
   float c, d, e;
   int i, j;
   printf("\t\t Manejo de punteros en C ");
   printf("\t\n Introduzca el primer munero: ");
   scanf("%f",&c);
   printf("\t\n Introduzca el segundo munero: ");
   scanf("%f",&d);
   
   a = &c;
   b = &d;

   j = c;
   
   *a = (*a)+(*b); 
   printf("\t La suma es: %f \n",*a);
   
   *a = (*a)-(*b)-(*b);
   printf("\t La resta es: %f \n",*a);
   
   *a = (*a) + (*b);
   e = 0;
   while((*a) >= (*b))
   {
      *a = (*a) - (*b);
      e++;
   }
   printf("\t La division es: %f \n",e); 
   
   *a = 0;
   i = 0;
   while(i < j)
   {
      *a = (*a) + (*b);
      i++;
   }
   printf("\t La multiplicacion es: %f \n",*a);
  
}
