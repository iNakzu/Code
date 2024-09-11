/*
Considere el proceso de retiro de equipaje de pasajeros en un aeropuerto una vez que el
avión aterriza, el equipaje es llevado a una cinta para su retiro. Los pasajeros del vuelo
esperan su/sus maletas y las retiran a medida que van apareciendo. Considere que cada
equipaje tiene asignado un rut de propietario y un peso. Un pasajero puede tener más de un equipaje.

Hay un operador por cinta que va poniendo las maletas en la cinta.

Se solicita,

a) Decidir qué estructura de datos dinámica mejor se adecúa a este proceso e
implementar las clases correspondientes para el caso, considerando atributos,
constructores y metodos de acceso y definicion (getters y setters) de atributos. (10 pts)

b) Implementar un método agregar_equipaje(string rut, float peso) para el operador, que
agregue el equipaje. Solo pueden haber hasta 5 equipajes por pasajero. (10 pts)

c) Implementar un método int buscar_maleta(string rut) para el operador que retorna el
indice de la primera maleta asociada al rut ingresado que encuentre. (5 pts)

d) Implementar un método entregar_equipaje(Pasajero *pasajero) para el operador, que
busque en la cinta el equipaje segun el rut y lo entregue al pasajero (retirando a su vez
el equipaje de la cinta). (15 pts)

e) Implementar un método obtener_equipaje_mayor_peso() para el pasajero. Que retorne el
equipaje con mayor peso de su coleccion de equipajes. (5 pts)

f) Implementar un método obtener_equipaje_menor_peso() para el pasajero. Que retorne el
equipaje con menor peso de su coleccion de equipajes. (5 pts)

g) Implementar un método informacion_cinta() para el operador, que imprima la cantidad
de maletas, el peso total en la cinta y promedio de pesos en la cinta. (10 pts)
*/

#include <iostream>
#include <vector>

class Equipaje
{
private:
    std::string rut;
    float peso;

public:
    Equipaje() {}
    Equipaje(std::string rut, float peso)
    {
        this->rut = rut;
        this->peso = peso;
    }
    std::string get_rut()
    {
        return rut;
    }
    float get_peso()
    {
        return peso;
    }
    void set_rut(std::string rut)
    {
        this->rut = rut;
    }
    void set_peso(int peso)
    {
        this->peso = peso;
    }
};

class Pasajero
{
private:
    std::string rut;
    std::vector<Equipaje *> maleta;

public:
    Pasajero() {}
    Pasajero(std::string rut)
    {
        this->rut = rut;
    }
    std::string get_rut()
    {
        return rut;
    }
    void set_rut(std::string rut)
    {
        this->rut = rut;
    }
    void agregar_maleta(Equipaje *equipaje)
    {
        maleta.push_back(equipaje);
    }
    float obtener_equipaje_mayor_peso()
    {
        if (maleta.empty())
        {
            return -1;
        }
        float max = maleta[0]->get_peso();
        for (int i = 1; i < maleta.size(); i++)
        {
            if (maleta[i]->get_peso() > max)
            {
                max = maleta[i]->get_peso();
            }
        }
        return max;
    }

    float obtener_equipaje_menor_peso()
    {
        if (maleta.empty())
        {
            return -1;
        }
        float min = maleta[0]->get_peso();
        for (int i = 1; i < maleta.size(); i++)
        {
            if (maleta[i]->get_peso() < min)
            {
                min = maleta[i]->get_peso();
            }
        }
        return min;
    }
};

class Operador
{
private:
    std::vector<Equipaje *> cinta;

public:
    Operador() {}
    void agregar_equipaje(std::string rut, float peso)
    {
        int count = 0;
        for (int i = 0; i < cinta.size(); i++)
        {
            if (cinta[i]->get_rut() == rut)
            {
                count++;
            }
        }
        if (count < 5)
        {
            Equipaje *equipaje = new Equipaje(rut, peso);
            cinta.push_back(equipaje);
        }
        else
        {
            std::cout << "El pasajero esta en el limite de maletas\n";
        }
    }
    int buscar_maleta(std::string rut)
    {
        int index = -1;
        for (int i = 0; i < cinta.size(); i++)
        {
            if (cinta[i]->get_rut() == rut)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    void entregar_equipaje(Pasajero *pasajero)
    {
        for (int i = 0; i < cinta.size(); i++)
        {
            if (cinta[i]->get_rut() == pasajero->get_rut())
            {
                pasajero->agregar_maleta(cinta[i]);
                cinta.erase(cinta.begin() + i);
                i--; // Decrementa i para no saltarte el siguiente elemento
            }
        }
    }
    void informacion_cinta()
    {
        float peso_total = 0;
        for (int i = 0; i < cinta.size(); i++)
        {
            peso_total += cinta[i]->get_peso();
        }
        std::cout << "La cantidad de maletas de la cinta es de: " << cinta.size() << std::endl;
        std::cout << "El peso total de maletas que hay en la cinta es de: " << peso_total << std::endl;
        std::cout << "El promedio del peso que hay en la cinta es de: " << peso_total / cinta.size() << std::endl;
    }
};

int main()
{
    Pasajero *p1 = new Pasajero("21503503-4");
    Operador *o1 = new Operador();
    o1->agregar_equipaje("21503503-4", 5);
    o1->agregar_equipaje("21503503-4", 2);
    o1->agregar_equipaje("21503503-4", 7);
    o1->agregar_equipaje("21503503-4", 1);
    o1->agregar_equipaje("21503503-4", 0.5);
    o1->buscar_maleta("21503503-4");
    o1->informacion_cinta();
    o1->entregar_equipaje(p1);
    std::cout << "El equipaje con mayor peso del pasajero " << p1->get_rut() << " es de " << p1->obtener_equipaje_mayor_peso() << " kg" << std::endl;
    std::cout << "El equipaje con menor peso del pasajero " << p1->get_rut() << " es de " << p1->obtener_equipaje_menor_peso() << " kg" << std::endl;
}
