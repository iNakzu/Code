/*
Algoritmos:
● Para finalizar con la materia, enunciamos dos métodos bien útiles que
pueden ser encontrados en la librería <algorithm>

    ● sort
    ● binary_search

● sort nos permitirá ordenar los elementos (por ejemplo de un vector) en un
cierto orden (por defecto de menor a mayor), utiliza IntroSort, una mezcla
entre quicksort, heapsort e insertion sort.

● binary_search nos permitirá efectuar una búsqueda (binaria) de algún
elemento en, por ejemplo, un vector (el cual debe estar ordenado)
*/

/*
1. La empresa x está desarrollando una nueva funcionalidad para su servicio de
streaming, en especial para efectuar speed-runs entre amigos. Esta funcionalidad está
destinada para que la gente que mira, pueda efectuar sus donaciones mientras los amigos
compiten. Esta funcionalidad posee una clase con los siguientes elementos:
● Un vector de stacks, en donde se van guardando las donaciones. La posición i del vector
corresponde a las donaciones efectuadas al jugador i.
● Un vector de strings, con los nombres de los jugadores(mismo orden con lo anterior).

Se pide:

● Un método que permita agregar un jugador (entrada del método es el nombre)
● Un método que permita agregar una donación para un jugador (entrada del método es la
donación y el nombre del jugador)
● Un método que permita retornar el nombre del jugador que recaudó más dinero.
● Un método que permita transferir las donaciones de un jugador a otro. (entrada ambos
nombres)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

class Stream
{
private:
    std::vector<std::stack<int>> donaciones;
    std::vector<std::string> jugadores;

public:
    // Método para agregar un nuevo jugador
    void agregar_jugador(std::string nombre)
    {
        // Agregamos el nombre del jugador al final de la lista de jugadores
        jugadores.push_back(nombre);

        // Agregamos un nuevo stack de donaciones vacío al final de la lista de donaciones
        donaciones.push_back(std::stack<int>());
    }

    // Método para agregar una donación a un jugador
    void agregar_donacion(int donacion, std::string nombre)
    {
        // Recorremos la lista de jugadores
        for (int i = 0; i < jugadores.size(); i++)
        {
            // Si encontramos al jugador con el nombre dado
            if (jugadores[i] == nombre)
            {
                // Agregamos la donación al stack de donaciones del jugador
                donaciones[i].push(donacion);

                // Salimos del bucle, ya que hemos encontrado al jugador y agregado la donación
                break;
            }
        }
    }
    std::string jugador_con_mas_dinero()
    {
        // Inicializamos la variable que guardará el máximo de donaciones y el jugador que las hizo
        int max_donaciones = 0;
        std::string max_jugador;

        // Recorremos la lista de jugadores
        for (int i = 0; i < jugadores.size(); i++)
        {
            // Inicializamos la suma de donaciones para el jugador actual
            int suma = 0;

            // Creamos una copia del stack de donaciones del jugador actual
            std::stack<int> temp = donaciones[i];

            // Mientras el stack de donaciones no esté vacío
            while (!temp.empty())
            {
                // Sumamos la donación en el top del stack a la suma total
                suma += temp.top();

                // Eliminamos la donación en el top del stack
                temp.pop();
            }

            // Si la suma de donaciones del jugador actual es mayor que el máximo actual
            if (suma > max_donaciones)
            {
                // Actualizamos el máximo y el jugador con más donaciones
                max_donaciones = suma;
                max_jugador = jugadores[i];
            }
        }

        // Devolvemos el nombre del jugador con más donaciones
        return max_jugador;
    }
    void transferir_donacion(std::string remitente, std::string destinatario)
    {
        int indice_remitente = -1;
        int indice_destinatario = -1;

        // Encuentra los índices de los jugadores
        for (int i = 0; i < jugadores.size(); i++)
        {
            if (jugadores[i] == remitente)
            {
                indice_remitente = i;
            }
            if (jugadores[i] == destinatario)
            {
                indice_destinatario = i;
            }
        }

        // Si ambos jugadores existen, transfiere las donaciones
        if (indice_remitente != -1 && indice_destinatario != -1)
        {
            while (!donaciones[indice_remitente].empty())
            {
                donaciones[indice_destinatario].push(donaciones[indice_remitente].top());
                donaciones[indice_remitente].pop();
            }
        }
    }
};