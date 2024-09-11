/*
Cree la clase “trabajador” que tiene como atributo nombre(string) y salario(int) y un
método Void información() que muestra la información del trabajador, luego cree dos
clases heredadas de la anterior llamadas “Empleado” y “Gerente”, la clase Empleado tiene
como atributos nombre(string), salario(int) y cargo(string) y el método heredado
información, la clase Gerente tiene como atributos nombre(string), salario(int) y
departamento(string) y el método heredado información.
En el main haga un objeto por cada clase y utilize su respectivo método.
*/

#include <iostream>
#include <string>

class Trabajador
{
protected:
    std::string nombre;
    int salario;

public:
    Trabajador(std::string nombre, int salario)
    {
        this->nombre = nombre;
        this->salario = salario;
    }
    void informacion()
    {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Salario: $" << salario << "" << std::endl;
    }
};

class Empleado : public Trabajador
{
private:
    std::string cargo;

public:
    Empleado(std::string nombre, int salario, std::string cargo) : Trabajador(nombre, salario)
    {
        this->cargo = cargo;
    }
    void informacion()
    {
        Trabajador::informacion(); // Llama a la función de la clase base
        std::cout << "Cargo: " << cargo << "\n" << std::endl;
    }
};

class Gerente : public Trabajador
{
    std::string departamento;

public:
    Gerente(std::string nombre, int salario, std::string departamento) : Trabajador(nombre, salario)
    {
        this->departamento = departamento;
    }
    void informacion()
    {
        Trabajador::informacion(); // Llama a la función de la clase base
        std::cout << "Departamento: " << departamento << "\n" << std::endl;
    }
};

int main()
{
    Gerente *g1 = new Gerente("Juan", 3000, "Epic Games");
    g1->informacion();
    Empleado *e1 = new Empleado("Manuel", 45000, "Steam");
    e1->informacion();
}