/*
Crear la clase Persona, la cual debe tener una edad y nombre. Crear una
cola de personas en main. Crear la función
mostrar_fila(queue<Persona> f) que imprime los nombres de la
lista de personas y sus edades
*/

#include <iostream>
#include <queue>

using namespace std;

class Persona
{
private:
    int edad;
    string nombre;

public:
    Persona(int edad, string nombre)
    {
        this->edad = edad;
        this->nombre = nombre;
    }
    string get_nombre()
    {
        return nombre;
    }
    int get_edad()
    {
        return edad;
    }
};

void mostrar_fila(queue<Persona> cola)
{
    while (!cola.empty())
    {
        cout << cola.front().get_edad() << " " << cola.front().get_nombre() << endl;
        cola.pop();
    }
}

int main()
{
    queue<Persona> cola;
    cola.push(Persona(36, "Victor"));
    cola.push(Persona(37, "Carolina"));
    cola.push(Persona(30, "Javiera"));
    mostrar_fila(cola);
}
