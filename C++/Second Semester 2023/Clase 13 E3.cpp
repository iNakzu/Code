/*
Consideremos un sistema de manejo de backlog de videojuegos (videojuegos acumulados, aún
sin jugar). Cada juego posee 3 características: idjuego (entero y único), nombre y precio. Por
otro lado, los jugadores tienen un nombre y un conjunto de juegos (que serán modelados como stack).
1. Implemente las clases del problema: Juego y Jugador.
2. Implementar el método , agregar_juego(Juego J), en la clase Jugador. Esta debe agregar
un juego al stack, si y sólo si, el juego no está en el stack (revisar por id).
3. Implementar el método, costo_backlog(), en la clase Jugador. Este método debe retornar
el costo total del backlog actual del jugador.
4. Crear una función que reciba un vector de Jugadores y retorne el jugador con el backlog
de mayor costo.
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Juego
{
private:
    int id_juego;
    std::string nombre;
    int precio;

public:
    Juego(int id_juego, std::string nombre, int precio)
    {
        this->id_juego = id_juego;
        this->nombre = nombre;
        this->precio = precio;
    }
    int get_id_juego()
    {
        return id_juego;
    }
    int get_precio()
    {
        return precio;
    }
};

class Jugadores
{
private:
    std::string nombre;
    std::stack<Juego> conjunto_juegos;

public:
    Jugadores(std::string nombre, std::stack<Juego> conjunto_juegos)
    {
        this->nombre = nombre;
        this->conjunto_juegos = conjunto_juegos;
    }
    void agregar_juego(Juego x)
    {
        bool found = false;
        std::stack<Juego> temp = conjunto_juegos;
        while (!temp.empty())
        {
            if (x.get_id_juego() == temp.top().get_id_juego())
            {
                std::cout << "El juego ya esta en el stack" << std::endl;
                found = true;
                return;
            }
            temp.pop();
        }
        if (!found)
        {
            conjunto_juegos.push(x);
        }
    }
    int costo_backlog()
    {
        int sum = 0;
        std::stack<Juego> temp = conjunto_juegos;
        while (!temp.empty())
        {
            sum += temp.top().get_precio();
            temp.pop();
        }
        return sum;
    }
};

Jugadores jugador_con_mayor_backlog(std::vector<Jugadores> jugadores)
{
    Jugadores jugador_mayor_backlog = jugadores[0];
    for (int i = 1; i < jugadores.size(); i++)
    {
        if (jugadores[i].costo_backlog() > jugador_mayor_backlog.costo_backlog())
        {
            jugador_mayor_backlog = jugadores[i];
        }
    }
    return jugador_mayor_backlog;
}

int main()
{
}