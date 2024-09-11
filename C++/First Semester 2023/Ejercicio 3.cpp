/*
Cree la función “factorial”, la cuál recibe como parámetro un número entero y retorna el valor del factorial de dicho número.
El parámetro que recibe la función debe ser ingresado por teclado dentro de la función main. No puede usar librerías matemáticas.
Recuerde que un factorial se calcula de forma que: 5! = 5 · 4 · 3 · 2 · 1
*/

#include <iostream>

int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    int num;
    cout << "Ingrese un digito (mayor o igual que cero) para calcular su factorial: !";
    cin >> num;
    if (num < 0)
    {
        cout << "El digito debe ser mayor o igual a cero" << endl;
        return -1;
    }
    else
    {
        std::cout << "El resultado es: " << factorial(num) << std::endl;
    }
    return 0;
}
