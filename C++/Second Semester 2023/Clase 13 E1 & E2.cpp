#include <iostream>
#include <stack> // Libreria necesaria para ocupar pilas
#include <queue>

/*
    Son del tipo LIFO (Last in First Out)
    Solo es posible ver al ultimo elemento ingresado
    Para poder crear un contenedor del tipo stack, se define: stack<tipo_dato> nombre_var;

    Metodos mas importantes:
        ● size(): retorna el tamaño del stack.
        ● empty(): retorna true si el stack está vacío, false en caso contrario.
        ● top(): accede al primer elemento.
        ● push(): agrega un elemento al comienzo.
        ● pop(): remueve el elemento del comienzo.
*/

/*
Ejercicio 1: Escriba una función que reciba una cola de números enteros y que la
imprima en el orden inverso. (usar stacks)
*/

// void imprimir_en_orden_inverso(std::queue<int> cola) {
//     std::stack<int> pila;
//     while (!cola.empty()) { // Transfiere los elementos de la cola a la pila
//         pila.push(cola.front());
//         cola.pop();
//     }
//     while (!pila.empty()) {
//         std::cout << pila.top() << " ";
//         pila.pop();
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::queue<int> cola;
//     cola.push(1);
//     cola.push(2);
//     cola.push(3);
//     cola.push(4);
//     cola.push(5);
//     imprimir_en_orden_inverso(cola);
// }

/*
Ejercicio 2: Escribir una función que reciba un stack de enteros positivos y que
retorne un stack en el mismo orden, pero sin números impares (solo puede usar stacks).
*/

std::stack<int> quitar_impares(std::stack<int> pila)
{
    std::stack<int> sin_impares;

    while (!pila.empty())
    {
        if (pila.top() % 2 == 0)
        {
            sin_impares.push(pila.top());
        }
        pila.pop();
    }
    return sin_impares;
}

int main()
{
    std::stack<int> pila;
    int input;

    while (input != 0)
    {
        std::cout << "Ingresa un numero para la pila (0 para salir): ";
        std::cin >> input;
        pila.push(input);
    }

    std::cout << "\nElementos de la pila: ";
    std::stack<int> temp = pila;
    while (!temp.empty())
    {
        std::cout << temp.top() << " ";
        temp.pop();
    }

    std::cout << "\nElementos de la nueva pila sin numeros pares: ";
    std::stack<int> nueva_pila_temp = quitar_impares(pila);
    while (!nueva_pila_temp.empty())
    {
        std::cout << nueva_pila_temp.top() << " ";
        nueva_pila_temp.pop();
    }
    std::cout << "\n";
}
