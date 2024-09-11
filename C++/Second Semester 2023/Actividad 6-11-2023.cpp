#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Juego
{
public:
    Juego(string nombre, float tiempo, string consola)
    {
        this->nombre = nombre;
        this->tiempo = tiempo;
        this->consola = consola;
    }

    string get_nombre()
    {
        return nombre;
    }

    void set_nombre(string nombre)
    {
        this->nombre = nombre;
    }

    float get_tiempo()
    {
        return tiempo;
    }

    void set_tiempo(float tiempo)
    {
        this->tiempo = tiempo;
    }

    string get_consola()
    {
        return consola;
    }

    void set_consola(string consola)
    {
        this->consola = consola;
    }

private:
    string nombre, consola;
    float tiempo;
};

class ActividadUsuarios
{
public:
    void agregar_juego(string rut)
    {
        map<string, stack<Juego>>::iterator it;
        it = juegos_por_jugar.find(rut);

        if (it != juegos_por_jugar.end())
        {
            string nombre;
            float tiempo;
            string consola;
            cout << "Ingrese nombre del juego: ";
            cin >> nombre;
            cout << "Ingrese horas necesarias para completar el juego: ";
            cin >> tiempo;
            cout << "Ingrese el tipo de consola donde se juega: ";
            cin >> consola;
            it->second.push(Juego(nombre, tiempo, consola));
        }
    }

    void terminar_juego(string rut)
    {
        map<string, stack<Juego>>::iterator it1;
        it1 = juegos_por_jugar.find(rut);

        map<string, stack<Juego>>::iterator it2;
        it2 = juegos_terminados.find(rut);

        if (it2 != juegos_terminados.end())
        {
            it2->second.push(it1->second.top());
            it1->second.pop();
        }
        else
        {
            stack<Juego> aux;
            aux.push(it1->second.top());
            juegos_terminados.insert(make_pair(rut, aux));
        }
    }

    void mostrar_juego_consola(string rut)
    {
        map<string, stack<Juego>>::iterator it;
        it = juegos_terminados.find(rut);
        stack<Juego> aux = it->second;

        if (it != juegos_terminados.end())
        {
            while (!aux.empty())
            {
                cout << aux.top().get_nombre() << endl;
                aux.pop();
            }
        }
    }

    void tiempos_jugados()
    {
        map<string, stack<Juego>>::iterator it;
        float tiempo_total = 0;

        for (it = juegos_terminados.begin(); it != juegos_terminados.end(); it++)
        {
            stack<Juego> aux = it->second;
            while (!aux.empty())
            {
                tiempo_total += aux.top().get_tiempo();
                aux.pop();
            }
            cout << it->first << endl;
            cout << tiempo_total << endl;
        }
    }

private:
    map<string, stack<Juego>> juegos_por_jugar;
    map<string, stack<Juego>> juegos_terminados;
};

int main()
{
}