/*
Cree la función “collatz”, la cuál recibe un número entero n. Dentro de la función, verifique si el número es par o impar.
Si el número es par, deberá dividir el número por dos. Si el número es impar, deberá multiplicar el número por 3 y sumarle 1.
Repita este proceso hasta que el número sea igual a 1. Finalmente, retorne el número de veces que se realizaron estos cálculos e imprímalo en su función main.
*/

#include <iostream>

int collatz(int n)
{
    int sum;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            sum++;
        }
        else
        {
            n = (n * 3) + 1;
            sum++;
        }
    }
    return sum;
}
int main()
{
    int x;
    std::cout << "La conjetura de Collatz" << std::endl;
    std::cout << "Ingrese un digito: "; std::cin >> x;

    std::cout << collatz(x) << std::endl;
}