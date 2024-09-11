#include <iostream>
#include <queue> // Fifo: first in, first out

int main()
{
    std::queue<int> cola;

    cola.push(10);
    cola.push(20);
    cola.push(30);
    cola.push(40);
    cola.push(50);
    cola.push(50);
    cola.push(60);

    std::queue<int> aux = cola;

    while (!aux.empty())
    { // Recorrer cola
        std::cout << aux.front() << " ";
        aux.pop();
    }

    std::cout << "\n";

    std::cout << cola.size(); // Los elementos siguen intactos ya que recorrimos una cola auxiliar
}