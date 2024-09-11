/*
Dentro de su función main, cree dos arreglos de enteros de tamaño 12. Luego, cree un ciclo tal que pregunte dos valores ingresados por teclados,
donde el primero lo guardará en el primer arreglo y el segundo en el segundo arreglo. Haga esto hasta que ambos arreglos posean todos sus espacios ocupados.
Finalmente haga un ciclo tal que compare ambos valores de los arreglos en la misma posición, e imprima qué número es mayor entre ambos.
Deberá imprimir esto para los 12 valores.
*/

#include <iostream>
using namespace std;

int main()
{
    int first_array[12];
    int second_array[12];

    for (int i = 0; i < 12; i++)
    {
        int f, s;
        cout << "Valor del elemento " << i << " del 1er array --> ";
        cin >> f;
        first_array[i] = f;
        cout << "Valor del elemento " << i << " del 2do array --> ";
        cin >> s;
        second_array[i] = s;
    }
    cout << "\n";
    for (int i = 0; i < 12; i++)
    {
        if (first_array[i] > second_array[i])
        {
            cout << "En el elemento " << i << " el numero mayor es " << first_array[i] << ", viene del 1er array" << endl;
        }
        else if (second_array[i] > first_array[i])
        {
            cout << "En la posicion " << i << " el numero mayor es " << second_array[i] << ", viene del 2do array" << endl;
        }
        else
        {
            cout << "En la posición " << i << " ambos valores son iguales" << endl;
        }
    }
}