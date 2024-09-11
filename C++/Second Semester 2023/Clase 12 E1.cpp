#include <iostream>
#include <queue> // Libreria necesaria para ocupar colas
using namespace std;

/*
    Son del tipo FIFO (First in First Out)
    Similar al <vector>, sin embargo, no es posible acceder a los elementos que estan al medio
    Lo anterior implica que solo puedo "ver" el primer y ultimo elemento

    Metodos mas importantes:
        ● size(): retorna el tamaño de la cola.
        ● empty(): retorna true si la cola está vacía, false en caso contrario.
        ● front(): accede al primer elemento.
        ● back(): accede al último elemento.
        ● push(): agrega un elemento al final.
        ● pop(): elimina el primer elemento.
*/

/*
    Priority Queue:
    Para poder crear un contenedor del tipo priority queue, se define: priority_queue<tipo_dato> nombre_var;
*/

/*
Pedirle a un usuario números enteros. Todos los positivos se van poniendo
en una cola. Si el usuario ingresa un número negativo hay que desencolar
(sacar de la cola), en caso de existir, un elemento y mostrarlo. Al poner un
0 hay que desencolar todos los elementos, mostrarlos y terminar el
programa.
*/

int main()
{
    queue<int> cola;
    int num;
    while (true)
    {
        cout << "Ingresa un numero: ";
        cin >> num;
        if (num > 0)
        {
            cola.push(num);
        }
        else if (num < 0 && cola.size() > 0)
        {
            cout << "Elemento desencolado: " << cola.front() << endl;
            cola.pop();
        }
        else if (num == 0)
        {
            cout << "Elementos de la cola: ";
            while (!cola.empty())
            {
                cout << cola.front() << " ";
                cola.pop();
            }
            cout << endl;
            break;
        }
    }
}
