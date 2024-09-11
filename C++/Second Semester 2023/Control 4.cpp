/*
Un supermercado necesita elaborar un sistema para controlar los pagos que se hacen en cada
una de sus cajas. Actualmente, se tiene:
1. Una clase Caja, la cual posee el monto recaudado como atributo, getters y setters.
2. La clase Supermercado, la cual tiene inicialmente 30 cajas. Asuma que el id de las
cajas comienza en 0, y va aumentando de 1 en 1.

Se pide:

a) Defina la estructura de la clase Supermercado, con los elementos necesarios para
satisfacer los requerimientos pedidos. (10 puntos)
b) Un método que permita agregar una caja al supermercado (10 puntos)
c) void AtenderCola(Queue<int> q, int idCaja) en la clase Supermercado. Este método debe
permitir procesar una cola de montos asociados a pagos de mercadería. (20 puntos)
d) Un método que permita retornar el id de la caja que ha recaudado la mayor cantidad
de dinero. (20 puntos)
*/

#include <iostream>
#include <vector>
#include <queue>

class Caja
{
private:
    int monto = 0;

public:
    Caja() {}
    void set_monto(int monto)
    {
        this->monto = monto;
    }
    int get_monto()
    {
        return monto;
    }
};

class Supermercado
{
private:
    std::vector<Caja> cajas;

public:
    Supermercado()
    {
        for (int i = 0; i < 30; i++)
        {
            cajas.push_back(Caja());
        }
    }
    void agregar_caja()
    {
        cajas.push_back(Caja());
        std::cout << "Se ha agregado una caja mas al vector, ahora su tamanho es de " << cajas.size() << std::endl;
    }
    void atender_cola(std::queue<int> &q, int id_caja)
    {
        int sum = 0;
        while (!q.empty())
        {
            sum += q.front();
            q.pop();
        }
        cajas[id_caja].set_monto(cajas[id_caja].get_monto() + sum);
        std::cout << "Se ha atendido a la cola en la caja numero " << id_caja << std::endl;
        std::cout << "Caja " << id_caja << ": " << cajas[id_caja].get_monto() << std::endl;
    }
    int mayor_recaudacion()
    {
        int max = 0;
        int id = -1;
        for (int i = 0; i < cajas.size(); i++)
        {
            if (cajas[i].get_monto() > max)
            {
                max = cajas[i].get_monto();
                id = i;
            }
        }
        return id;
    }
};

int main()
{
    Supermercado super;
    std::queue<int> c1;
    std::queue<int> c2;

    c1.push(2000);
    c1.push(3000);

    c1.push(5000);
    c2.push(12000);

    super.atender_cola(c1, 0);
    super.atender_cola(c2, 2);
    std::cout << "La caja con mayor recaudacion es la numero " << super.mayor_recaudacion() << std::endl;
}