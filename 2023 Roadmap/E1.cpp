#include <iostream>

void operadores()
{
    // Operadores aritméticos
    std::cout << "Operadores aritméticos:" << std::endl;

    std::cout << "Suma: 7 + 3 = " << 7 + 3 << std::endl; // Suma
    std::cout << "Resta: 7 - 3 = " << 7 - 3 << std::endl; // Resta
    std::cout << "Multiplicacion: 7 * 3 = " << 7 * 3 << std::endl; // Multiplicacion
    std::cout << "Division: 7 / 3 = " << 7 / 3 << std::endl; // Division
    std::cout << "Modulo: 7 % 3 = " << 7 % 3 << std::endl; // Modulo

    // Operadores lógicos
    std::cout << "\nOperadores lógicos (0 es false y 1 es true):" << std::endl;

    std::cout << "AND: 7 + 3 == 10 && 3 * 2 == 6 es " << (7 + 3 == 10 && 3 * 2 == 6) << std::endl;
    std::cout << "OR: 7 + 3 == 10 || 3 * 2 == 6 es " << (7 + 3 == 10 || 3 * 2 == 6) << std::endl;
    std::cout << "NOT: !(7 + 3 == 10) es " << !(7 + 3 == 10) << std::endl;

    // Operadores de comparación
    std::cout << "\nOperadores de comparación (0 es false y 1 es true):" << std::endl;

    std::cout << "Igualdad: 7 == 3 es " << (7 == 3) << std::endl; // Igualdad
    std::cout << "Desigualdad: 7 != 3 es " << (7 != 3) << std::endl; // Desigualdad
    std::cout << "Mayor o igual que: 7 >= 3 es " << (7 >= 3) << std::endl; // Mayor o igual que
    std::cout << "Mayor que: 7 > 3 es " << (7 > 3) << std::endl; // Mayor que
    std::cout << "Menor o igual que: 7 <= 3 es " << (7 <= 3) << std::endl; // Menor o igual que
    std::cout << "Menor que: 7 < 3 es " << (7 < 3) << std::endl; // Menor que

    // Operadores de asignación
    std::cout << "\nOperadores de asignación:" << std::endl;

    int variable;
    std::cout << "Asignación: variable = 5 es " << (variable = 5) << std::endl; // Asignación
    std::cout << "Suma y asignación: variable += 5 es " << (variable += 5) << std::endl; // Suma y asignación
    std::cout << "Resta y asignación: variable -= 5 es " << (variable -= 5) << std::endl; // Resta y asignación
    std::cout << "Multiplicación y asignación: variable *= 5 es " << (variable *= 5) << std::endl; // Multiplicación y asignación
    std::cout << "División y asignación: variable /= 5 es " << (variable /= 5) << std::endl; // División y asignación
    std::cout << "Módulo y asignación: variable %= 5 es " << (variable %= 5) << std::endl; // Módulo y asignación
    std::cout << "Incremento: variable++ es " << (variable++) << std::endl; // Incremento
    std::cout << "Decremento: variable-- es " << (variable--) << std::endl; // Decremento

    // Operadores de bits
    std::cout << "\nOperadores de bits:" << std::endl;

    // 5 en binario: 101; 3 en binario: 011

    std::cout << "AND: 5 & 3: " << (5 & 3) << std::endl;  // Resultado: 1 (en binario: 001)
    std::cout << "OR: 5 | 3: " << (5 | 3) << std::endl;   // Resultado: 7 (en binario: 111)
    std::cout << "XOR: 5 ^ 3 : " << (5 ^ 3) << std::endl;  // Resultado: 6 (en binario: 110)
    std::cout << "NOT: ~5: " << (~5) << std::endl;     // Resultado: -6 (en binario: 110)
    std::cout << "Desplazamiento a la izquierda: 5 << 1 = " << (5 << 1) << std::endl;  // Resultado: 10 (en binario: 1010)
    std::cout << "Desplazamiento a la derecha: 5 >> 1 = " << (5 >> 1) << std::endl;   // Resultado: 2 (en binario: 10)
}

// Condicionales

void condicionales()
{
    int a = 5;
    int b = 10;

    std::cout << "\nCondicionales:" << std::endl;

    // if-else
    if (a < b)
    {
        std::cout << "a es menor que b" << std::endl;
    }
    else
    {
        std::cout << "a no es menor que b" << std::endl;
    }

    // switch
    switch (a)
    {
    case 5:
        std::cout << "a vale 5\n" << std::endl;
        break;
    default:
        std::cout << "a no vale 5\n" << std::endl;
        break;
    }
}

// Iterativas

void iterativas()
{
    int a = 5;

    std::cout << "Iterativas:" << std::endl;

    // for
    std::cout << "For:\n";
    for (int i = 1; i <= a; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // while
    std::cout << "\nWhile:\n";
    while (a > 0)
    {
        std::cout << a << " ";
        a--;
    }
    std::cout << std::endl;

    // do-while
    std::cout << "\nDo-while:\n";
    do
    {
        std::cout << "Este mensaje se imprime al menos una vez\n" << std::endl;
    } while (a != 0);
}

void excepciones()
{
    int a = 5;
    int b = 0;

    std::cout << "Excepciones:" << std::endl;

    try
    {
        if (b == 0)
        {
            throw "Division by zero condition!";
        }
        int c = a / b;
    }
    catch (const char *msg)
    {
        std::cerr << msg << std::endl;
    }
}

int main()
{
    operadores();
    condicionales();
    iterativas();
    excepciones();

    std::cout << std::endl;

    for (int i = 10; i <= 55; i++)
    {
        if (i % 2 == 0 && i % 3 != 0 && i != 16) 
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}