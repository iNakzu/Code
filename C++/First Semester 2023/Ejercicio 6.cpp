/*
Dentro de su función main, declare un arreglo de n números enteros, siendo n un número ingresado por teclado.
Luego, cree un ciclo el cuál le pida al usuario ingresar un número k hasta que llene el arreglo anteriormente creado.
Posteriormente, haga otro ciclo el cuál sume cada valor del arreglo e imprima el promedio final.
*/

#include <iostream>

int main()
{
    int x;
    std::cout << "Ingrese el tamanho del arreglo: ";
    std::cin >> x;
    int array[x];
    std::cout << "\n";

    for (int i = 0; i < x; i++)
    {
        int k;
        std::cout << "Ingrese el valor del elemento " << i << ": ";
        std::cin >> k;
        array[i] = k;
    }
    float sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += array[i];
    }
    std::cout << "\n";
    std::cout << "El valor total del arreglo es: " << sum << std::endl;
    float avg = sum / x;
    std::cout << "El promedio final del array es: " << avg << std::endl;
}