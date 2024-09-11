/*
Cree una clase llamada super_cola la cual va a tener solo una cola, haga el constructor vacío y cree
los siguientes métodos:
void agregar_elemento(int elemento),void encontrar_maximo(), void encontrar_minimo() y void
imprimir_cola().
Cree una super cola en el main y utilice al menos una vez cada uno de los métodos.
*/

#include <iostream>
#include <queue>

class SuperCola
{
private:
    std::queue<int> num;

public:
    void agregar_elemento(int elemento)
    {
        num.push(elemento);
    }
    void imprimir_cola()
    {
        std::queue<int> temp = num;

        std::cout << "Elementos de la cola: ";

        while (!temp.empty())
        {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
    void encontrar_maximo()
    {
        if (num.empty())
        {
            std::cout << "La cola esta vacia" << std::endl;
            return;
        }
        std::queue<int> temp = num;
        int numero_mayor = temp.front();

        while (!temp.empty())
        {
            if (temp.front() > numero_mayor)
            {
                numero_mayor = temp.front();
            }
            temp.pop();
        }
        std::cout << "Numero mayor: " << numero_mayor << std::endl;
    }
    void encontrar_minimo()
    {
        if (num.empty())
        {
            std::cout << "La cola esta vacia" << std::endl;
            return;
        }
        std::queue<int> temp = num;
        int numero_menor = temp.front();

        while (!temp.empty())
        {
            if (temp.front() < numero_menor)
            {
                numero_menor = temp.front();
            }
            temp.pop();
        }
        std::cout << "Numero menor: " << numero_menor << std::endl;
    }
};

int main()
{
    SuperCola *cola = new SuperCola();
    cola->agregar_elemento(3);
    cola->agregar_elemento(9);
    cola->agregar_elemento(78);
    cola->agregar_elemento(2);
    cola->agregar_elemento(38);
    cola->agregar_elemento(33);
    cola->imprimir_cola();
    cola->encontrar_maximo();
    cola->encontrar_minimo();
}