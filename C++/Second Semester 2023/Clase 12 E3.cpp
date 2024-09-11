/*
Una empresa reconocida mundialmente quiere enviar un conjunto de satélites al
espacio. Cada satélite cuenta con dos características: id y peso, ambos enteros.
Previo al envío de los satélites, la empresa necesita hacer simulaciones, y para ello
necesita de su ayuda con lo siguiente:
a. Escriba la clase Satélite, incluyendo getters/setters/constructor.
b. En el main, pedir al usuario que ingrese 6 satélites. Estos, deben ser
almacenados tanto en un vector como en una cola.
c. Crear una función que reciba un vector de satélites e imprima el contenido.
Escriba otra función que reciba la cola e imprima el contenido.
d. Crear una función que reciba una cola de satélites y un id. La función debe
retornar dicha cola sin el satélite que contenga ese id.
e. Crear dos funciones que retornen el peso total de todos los satélites. La
primera deberá recibir una cola y la otra un vector
*/

#include <iostream>
#include <vector>
#include <queue>

class Satelite
{
private:
    int id;
    int peso;

public:
    Satelite(int id, int peso)
    {
        this->id = id;
        this->peso = peso;
    }
    Satelite() {}
    void set_id(int id)
    {
        this->id = id;
    }
    void set_peso(int peso)
    {
        this->peso = peso;
    }
    int get_id()
    {
        return id;
    }
    int get_peso()
    {
        return peso;
    }
};

void imprimir_info_vector(std::vector<Satelite> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << "ID del satelite numero " << i + 1 << ": " << vect[i].get_id() << std::endl;
        std::cout << "Peso del satelite numero " << i + 1 << ": " << vect[i].get_peso() << std::endl;
    }
    std::cout << "\n";
}

void imprimir_info_cola(std::queue<Satelite> cola)
{
    int i = 1;
    while (!cola.empty())
    {
        std::cout << "ID del satelite numero " << i << ": " << cola.front().get_id() << std::endl;
        std::cout << "Peso del satelite " << i << ": " << cola.front().get_peso() << std::endl;
        cola.pop();
        i++;
    }
}

std::queue<Satelite> eliminar_sat(std::queue<Satelite> satelites, int id)
{
    std::queue<Satelite> nueva_cola;
    while (!satelites.empty())
    {
        Satelite sat = satelites.front();
        if (sat.get_id() != id)
        {
            nueva_cola.push(sat);
        }
        satelites.pop();
    }
    return nueva_cola;
}

int peso_total_vector(std::vector<Satelite> satelites)
{
    int total = 0;
    for (int i = 0; i < satelites.size(); i++)
    {
        total += satelites[i].get_peso();
    }
    return total;
}

int peso_total_cola(std::queue<Satelite> satelites)
{
    int total = 0;
    while (!satelites.empty())
    {
        total += satelites.front().get_peso();
        satelites.pop();
    }
    return total;
}

int main()
{
    std::vector<Satelite> vector_sat;
    std::queue<Satelite> cola_sat;

    for (int i = 0; i < 2; i++)
    {
        int id, peso;
        std::cout << "Ingrese el ID del satelite: ";
        std::cin >> id;
        std::cout << "Ingrese el peso del satelite: ";
        std::cin >> peso;

        Satelite sat(id, peso);
        vector_sat.push_back(sat);
        cola_sat.push(sat);
    }
    std::cout << "\n";
    std::cout << "Informacion Vector:" << std::endl;
    imprimir_info_vector(vector_sat);
    std::cout << "Informacion Cola:" << std::endl;
    imprimir_info_cola(cola_sat);
    std::cout << "\n";
    std::cout << "Peso total de la cola: " << peso_total_cola(cola_sat) << std::endl;
    std::cout << "Peso total del vector: " << peso_total_vector(vector_sat) << std::endl;

    int id;
    std::cout << "\nIngrese el ID del satelite a eliminar: ";
    std::cin >> id;
    std::cout << "La informacion de la nueva cola:" << std::endl;
    imprimir_info_cola(eliminar_sat(cola_sat, id));
}