/*
Utilizando un bucle que recorra los números del 1 al 100. Para cada número en ese rango, realiza lo siguiente:
Si el número es divisible por 3, imprime "Fizz".
Si el número es divisible por 5, imprime "Buzz".
Si el número es divisible tanto por 3 como por 5, imprime "FizzBuzz".
Si ninguna de las condiciones anteriores se cumple, imprime el número tal cual.
*/

#include <iostream>

void fizz_buzz()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (i % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
        }
        else if (i % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
        }

        else
        {
            std::cout << i << std::endl;
        }
    }
}

int main()
{
    fizz_buzz();
}