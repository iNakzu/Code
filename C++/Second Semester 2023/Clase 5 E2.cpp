/*
- Hacer una clase Persona, que tiene los atributos: edad y nombre. Debe incluir constructor (para inicializar edad y nombre), setters y getters.

- Crear además una clase Bus, que debe tiene los atributos: marca y un arreglo de 20 Personas. El constructor solo debe inicializar la marca.
  Programe sólo setters y getters para la marca.
- Crear el método (dentro de la clase Bus) desplegar(), que muestra por pantalla la información de las personas que se encuentran en dicho Automóvil.
- Crear el método (dentro de la clase Bus) addPersona(Persona p), que agrega una persona al Bus. Si está lleno, imprimir un error.
*/

#include <iostream>
#include <string>

class Persona
{
private:
    std::string name;
    int age;

public:
    Persona(std::string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void set_name(std::string name)
    { // Setter
        this->name = name;
    }

    std::string get_name()
    { // Getter
        return name;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    int get_age()
    {
        return age;
    }
};

class Bus
{
private:
    std::string marca;
    Persona *pasajeros[20];

public:
    Bus(std::string marca)
    {
        this->marca = marca;
        for (int i = 0; i < 20; i++)
        {
            pasajeros[i] = nullptr;
        }
    }

    void set_marca(std::string marca)
    {
        this->marca = marca;
    }

    std::string get_marca()
    {
        return marca;
    }

    void desplegar()
    {
        bool empty_bus = true;
        for (int i = 0; i < 20; i++)
        {
            if (pasajeros[i] != nullptr)
            {
                empty_bus = false;
                std::cout << "El pasajero numero " << i + 1 << " se llama " << pasajeros[i]->get_name() << " y tiene " << pasajeros[i]->get_age() << " anhos" << std::endl;
            }
            else
            {
                std::cout << "No hay mas pasajeros" << std::endl;
                break;
            }
        }
        if (empty_bus)
        {
            std::cout << "El bus esta vacio" << std::endl;
        }
    }

    void add_passenger(Persona p)
    {
        for (int i = 0; i < 20; i++)
        {
            if (pasajeros[i] == nullptr)
            {
                pasajeros[i] = new Persona(p.get_name(), p.get_age());
                return; // Importante salir del bucle después de agregar una persona
            }
        }
        // Si llegamos aquí, el bus está lleno
        std::cout << "El bus está lleno, no se puede agregar más pasajeros." << std::endl;
    }
};

int main()
{
    Bus mi_bus("Chevrolet");
    std::cout << "Marca del bus: " << mi_bus.get_marca() << std::endl;

    Persona p1("Antonio", 27);
    Persona p2("Matias", 13);
    Persona p3("Jorge", 51);
    Persona p4("Ignacio", 18);

    mi_bus.add_passenger(p1);
    mi_bus.add_passenger(p2);
    mi_bus.add_passenger(p3);
    mi_bus.add_passenger(p4);

    mi_bus.desplegar();
}
