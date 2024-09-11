#include <iostream>

// Variable global
int global_var = 10;

// Función sin parámetros ni retorno
void print_hello()
{
    std::cout << "Hello World!" << std::endl;
}

// Función con un parámetro sin retorno
void print_number(int num)
{
    std::cout << "El número es: " << num << std::endl;
}

// Función con múltiples parámetros sin retorno
void print_sum(int n1, int n2)
{
    std::cout << "La suma es: " << n1 + n2 << std::endl;
}

// Función con retorno
int square(int num)
{
    return num * num;
}

// Función que utiliza una variable global
void print_global_var()
{
    std::cout << "La variable global es: " << global_var << std::endl;
}

// Función que utiliza una variable local
void print_local_var()
{
    int local_var = 20;
    std::cout << "La variable local es: " << local_var << std::endl;
}

int exercise_function(std::string x, std::string y)
{
    int count = 0;
    for (int i = 1; i <= 100; i++) // Recorrer los números del 1 al 100
    {
        if (i % 3 == 0 && i % 5 == 0) // Si el número es múltiplo de 3 y 5
        {
            std::cout << x + y << std::endl;
        }
        else if (i % 3 == 0) // Si el número es múltiplo de 3
        {
            std::cout << x << std::endl;

        }
        else if (i % 5 == 0) // Si el número es múltiplo de 5
        {
            std::cout << y << std::endl;
        }
        else
        {
            std::cout << i << std::endl; // Si no es múltiplo de 3 ni de 5
            count++; // Contar el número de veces que aparece un número
        }
        
    }
    return count;
}

int main()
{
    print_hello();
    print_number(5);
    print_sum(3, 4);
    std::cout << "El cuadrado de 5 es: " << square(5) << std::endl;
    print_global_var();
    print_local_var();

    int count = exercise_function("Fizz", "Buzz");
    std::cout << "El total de veces que apareció el número fue: " << count << std::endl;
    return 0;
}