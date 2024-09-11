#include <iostream>
#include <stack> // Lifo: last in, first out

int main()
{
    std::stack<int> pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.push(40);
    pila.push(50);
    pila.push(60);

    std::stack<int> aux = pila; // Pila auxiliar para no modificar la original

    while (!aux.empty())
    { // Recorrer una pila
        std::cout << aux.top() << " ";
        aux.pop();
    }
    std::cout << "\n";

    std::cout << "Tamanho de la pila: " << pila.size() << std::endl;
}