// Ejercicio 2

#include <iostream>

class Auto
{
private:
    std::string marca;
    std::string estado;
    bool averia;

public:
    Auto(std::string marca, std::string estado)
    {
        this->marca = marca;
        this->estado = estado;
        if (estado == "Nuevo")
        {
            averia = false;
        }
        else
        {
            this->averia = averia;
        }
    }

    std::string get_estado()
    {
        return estado;
    }

    void reparar()
    {
        if (averia)
        {
            averia = false;
        }
        else
        {
            std::cout << "El auto ya esta reparado" << std::endl;
        }
    }
};

class Concesionaria
{
private:
    Auto *usado[15];
    Auto *nuevo[15];

public:
    void agregar_auto(Auto *x)
    {
        if (x->get_estado() == "Usado")
        {
            for (int i = 0; i < 15; i++)
            {
                usado[i] = x;
            }
        }
        else if (x->get_estado() == "Nuevo")
        {
            for (int i = 0; i < 15; i++)
            {
                nuevo[i] = x;
            }
        }
    }

    void revisar()
    {
        int usados = 0;
        int nuevos = 0;

        for (int i = 0; i < 15; i++)
        {
            if (usado[i] != nullptr)
            {
                usados++;
            }
            if (nuevo[i] != nullptr)
            {
                nuevos++;
            }
        }
        std::cout << "La cantidad de autos usados son " << usados << std::endl;
        std::cout << "La cantidad de autos nuevos son " << nuevos << std::endl;
    }
};