#include <iostream>

float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

float multiplicar(float a, float b)
{
    return a * b;
}

float dividir(float a, float b)
{
    return a / b;
}

void imprimir(float a)
{
    std::cout << "El resultado es: " << a << std::endl;
}

int main()
{
    std::cout << "-----|Bienvenido a la calculadora|-----" << std::endl;
    float sum;
    int opcion = -1;
    bool mostrar_menu = true;

    do
    {
        if (mostrar_menu)
        {
            std::cout << "0.- Salir" << std::endl;
            std::cout << "1.- Suma" << std::endl;
            std::cout << "2.- Resta" << std::endl;
            std::cout << "3.- Multiplicacion" << std::endl;
            std::cout << "4.- Dividir" << std::endl;
        }
        std::cout << "Elija una opcion -> ";
        std::cin >> opcion;
        if (opcion == 1)
        {
            float x, y;
            std::cout << "Digite el primer valor a sumar: "; std::cin >> x;
            std::cout << "Digite el segundo valor a sumar: "; std::cin >> y;
            imprimir(sumar(x, y));
            mostrar_menu = false;
        }
        else if (opcion == 2)
        {
            float x, y;
            std::cout << "Digite el primer valor a restar: "; std::cin >> x;
            std::cout << "Digite el segundo valor a restar: "; std::cin >> y;
            imprimir(restar(x, y));
            mostrar_menu = false;
        }
        else if (opcion == 3)
        {
            float x, y;
            std::cout << "Digite el primer valor a multiplicar: "; std::cin >> x;
            std::cout << "Digite el segundo valor a multiplicar: "; std::cin >> y;
            imprimir(multiplicar(x, y));
            mostrar_menu = false;
        }
        else if (opcion == 4)
        {
            float x, y;
            std::cout << "Digite el primer valor a dividir: "; std::cin >> x;
            std::cout << "Digite el segundo valor a dividir: "; std::cin >> y;
            imprimir(dividir(x, y));
            mostrar_menu = false;
        }
    } while (opcion != 0);
}
