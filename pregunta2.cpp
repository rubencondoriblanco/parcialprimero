// Estudiante: Ruben Condori Blanco
// Pregunta 2 
#include <iostream>
using namespace std;
int main()
{ 
   float *a, *b;
   float c, d, e;
   int i, j;
   cout<<"\t\t Manejo de punteros en C++ ";
   cout<<"\t\n Introduzca el primer munero: ";
   cin>>c;
   cout<<"\t\n Introduzca el segundo munero: ";
   cin>>d;
   
   a = &c;
   b = &d;

   j = c;
   
   *a = (*a)+(*b); 
   cout<<"\t La suma es: "<<*a<<endl;
   
   *a = (*a)-(*b)-(*b);
   cout<<"\t La resta es: "<<*a<<endl;
   
   *a = (*a) + (*b);
   e = 0;
   while((*a) >= (*b))
   {
      *a = (*a) - (*b);
      e++;
   }
   cout<<"\t La division es: "<<e<<endl; 
   
   *a = 0;
   i = 0;
   while(i < j)
   {
      *a = (*a) + (*b);
      i++;
   }
   cout<<"\t La multiplicacion es: "<<*a<<endl;
  
}
