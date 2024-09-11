/*
La reconocida empresa de telecomunicaciones Wovistel le solicita que programe su sistema de respaldo de clientes.
Cada cliente posee un RUT, nombre y número de teléfono. Además, un cliente puede tener uno de tres posibles planes: Básico, Avanzado y Premium.

a. Programe la clase "Cliente" con todos sus métodos getters, setters y un constructor.
b. Programe el método "imprimir()" de la clase "Cliente", que imprime: Nombre - RUT - plan.
c. Cree el método "mejorar_plan()", que actualiza el plan de un cliente: Si tenía el plan básico, ahora debe tener el plan avanzado; si tenía el plan avanzado, ahora debe tener el plan Premium. Si ya tenía el plan Premium, no se realiza ningún cambio.
d. Implemente la función "comparar(Cliente a, Cliente b)", que devuelve al cliente que posee el mejor plan. Se asume que estos clientes nunca tienen el mismo plan.
*/

#include <iostream>
#include <string>

class Cliente
{
private:
    int rut;
    std::string name;
    int phone_number;
    int plan;

public:
    Cliente(int rut, std::string name, int phone_number, int plan)
    {
        this->rut = rut;
        this->name = name;
        this->phone_number = phone_number;
        this->plan = plan;
    }

    // Setters
    void set_rut(int rut)
    {
        this->rut = rut;
    }

    void set_name(std::string name)
    {
        this->name = name;
    }

    void set_phone_number(int phone_number)
    {
        this->phone_number = phone_number;
    }

    void set_plan(int plan)
    {
        this->plan = plan;
    }

    // Getters
    int get_rut()
    {
        return rut;
    }

    std::string get_name()
    {
        return name;
    }

    int get_phone_number()
    {
        return phone_number;
    }

    int get_plan()
    {
        return plan;
    }

    void imprimir()
    {
        std::cout << "Nombre del cliente: " << name;
        std::cout << "\nRut: " << rut;
        std::cout << "\nNumero: " << phone_number;
        if (plan == 1)
        {
            std::cout << "\nPlan: Basico" << std::endl;
        }
        else if (plan == 2)
        {
            std::cout << "\nPlan: Avanzado" << std::endl;
        }
        else if (plan == 3)
        {
            std::cout << "\nPlan: Premium" << std::endl;
        }
        std::cout << "\n";
    }

    void mejorar_plan()
    {
        if (plan == 1)
        {
            plan = 2;
            std::cout << "Tu plan se ha mejorado a Avanzado" << std::endl;
        }
        else if (plan == 2)
        {
            plan = 3;
            std::cout << "Tu plan se ha mejorado a Premium" << std::endl;
        }
        else
        {
            std::cout << "No se puede mejorar el plan ya que tienes el plan Premium" << std::endl;
        }
    }
};

void comparar(Cliente x, Cliente y)
{
    if (x.get_plan() > y.get_plan())
    {
        std::cout << "El cliente " << x.get_name() << " tiene un mejor plan que el cliente " << y.get_name() << "\n" << std::endl;
    }
    else if (y.get_plan() > x.get_plan())
    {
        std::cout << "El cliente " << y.get_name() << " tiene un mejor plan que el cliente " << x.get_name() << "\n" << std::endl;
    }
    else
    {
        std::cout << "Los clientes " << x.get_name() << " y " << y.get_name() << " tienen el mismo plan" << "\n" << std::endl;
    }
}

int main()
{
    Cliente c1(217309603, "Ignacio", 31233585, 3);
    Cliente c2(139670973, "Jorge", 31238581, 3);
    comparar(c1, c2);
    c1.imprimir();
    c2.imprimir();
}