/*
Programe una función void contar_impar_par(int array[], int largo) que evalúe la cantidad de números pares e impares de un arreglo e imprima su cantidad.
El problema es que el arreglo contiene muchos ceros y el profesor le pidió que contara solo los números positivos mayores a cero.
Programe el main que lea un arreglo de tamaño 10 y utilizando la función descrita imprima la estadística solicitada.
*/

#include <iostream>

void contar_impar_par(int array[], int largo)
{
    int num_impar = 0, num_par = 0;
    for (int i = 0; i < largo; i++)
    {
        if (array[i] > 0)
        {
            if (array[i] % 2 == 0)
            {
                num_par++;
            }
            if (array[i] % 2 != 0)
            {
                num_impar++;
            }
        }
    }
    std::cout << "La cantidad de numeros impares es: " << num_impar << "\n";
    std::cout << "La cantidad de de numeros pares es: " << num_par << "\n";
}

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Digite el valor del indice " << i << ": ";
        std::cin >> array[i];
    }
    contar_impar_par(array, 10);
}