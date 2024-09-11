#include <iostream>
#include <set> // Libreria necesaria para el uso de sets
#include <queue>

/*
    ● Los sets (conjuntos) son contenedores que nos permiten almacenar datos,
    usando para ello un cierto orden (función comparadora, por defecto de
    mayor a menor).
    ● Todo elemento en el conjunto es único, por ejemplo, si es un set de enteros
    e intento agregar el número “3” dos veces, solo se agrega una vez.
    ● Los elementos no pueden ser modificados en el conjunto, pero sí eliminados.
    ● No hay índices para poder recorrer, se debe usar iteradores.
    Para poder crear un contenedor del tipo set, se define: set<tipo_dato> nombre_var

    Métodos importantes
    ● size(): retorna el tamaño del set.
    ● empty(): retorna true si el map está vacío, false en caso contrario.
    ● erase(): elimina un elemento
    ● insert(): agrega un elemento
    ● find(): busca un elemento y retorna un iterador
    ● count(g): retorna 1 si el elemento g está presente, y 0 en caso contrario.
    ● clear(): elimina todo el contenido
*/

using namespace std;

void mostrar_union(priority_queue<int> pq1, priority_queue<int> pq2)
{
    set<int> set;
    while (!pq1.empty())
    {
        set.insert(pq1.top());
        pq1.pop();
    }
    while (!pq2.empty())
    {
        set.insert(pq2.top());
        pq2.pop();
    }
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    pq1.push(1);
    pq1.push(3);
    pq1.push(5);
    pq2.push(2);
    pq2.push(4);
    pq2.push(6);
    mostrar_union(pq1, pq2); // Debería mostrar: 1 2 3 4 5 6
    return 0;
}
