/*
Ingrese n numeros y obtenga la última posición del arreglo. Obtenga el promedio de los numeros
*/

#include <iostream>

int main()
{
   int num; float suma = 0;
   std::cout << "Cuantos numeros va a ingresar: ";
   std::cin >> num;
   float arreglo[num];
   std::cout << "\n";

   for (int i = 0; i < num; i++)
   {
      std::cout << "Ingrese el numero " << i + 1 << ": ";
      std::cin >> arreglo[i];
      suma += arreglo[i];
   }

   float promedio = suma / num;
   int ultima_posicion = arreglo[num - 1];

   std::cout << "\n";
   std::cout << "El promedio es: " << promedio << std::endl;
   std::cout << "El valor de la ultima posicion del arreglo es de: " << ultima_posicion << std::endl;
}