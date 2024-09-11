/*
Construya la función int suma_divisores(int n) que recibe un número y devuelve la sumatoria de los divisores de un número (sin considerar el mismo número).
Invoque la funcion desde el main.
*/

#include <iostream>

int suma_divisores(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        { 
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int x;

    std::cout << "Digite un numero -> ";
    std::cin >> x;
    std::cout << "La sumatoria de sus divisores es -> " << suma_divisores(x) << std::endl;

    if (x == suma_divisores(x))
    {
        std::cout << "El numero es perfecto";
    }
    else if (suma_divisores(x) == 1)
    {
        std::cout << "El numero es primo";
    }
    else
    {
        std::cout << "El numero no es perfecto ni primo";
    }
}