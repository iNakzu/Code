/*
Disenhe un programa que simule un sistema de gestión de turnos en una clínica médica. El
programa debe permitir al usuario realizar las siguientes operaciones:
1)Agregar un paciente a la lista de espera.
2)Atender al próximo paciente en la lista.
3)Mostrar la lista de espera.
4)Salir del programa.
*/

#include <iostream>
#include <queue>

class paciente
{
private:
    std::string nombre;
    std::string rut;

public:
    paciente(std::string nombre, std::string rut)
    {
        this->nombre = nombre;
        this->rut = rut;
    }
    void imprimir_informacion()
    {
        std::cout << "Nombre: " << this->nombre << ", Rut: " << this->rut << std::endl;
    }
};

class gestor_turnos
{
private:
    std::queue<paciente *> pacientes;

public:
    gestor_turnos() {}
    void agregar_paciente_lista_espera(paciente *paciente)
    {
        pacientes.push(paciente);
    }
    void atender_paciente_lista_espera()
    {
        if (pacientes.empty())
        {
            std::cout << "No hay nadie para atender" << std::endl;
            return;
        }
        std::cout << "Paciente Atendido: ";
        pacientes.front()->imprimir_informacion();
        pacientes.pop();
    }
    void imprimir_lista_espera()
    {
        if (pacientes.empty())
        {
            std::cout << "No hay nadie en la lista de espera" << std::endl;
            return;
        }
        std::queue<paciente *> temp = pacientes;
        std::cout << "Pacientes en lista de espera:\n";
        while (!temp.empty())
        {
            temp.front()->imprimir_informacion();
            temp.pop();
        }
    }
};

int main()
{
    gestor_turnos *clinica = new gestor_turnos();

    // clinica->agregar_paciente_lista_espera(new paciente("Ignacio", "21730960-3"));
    // clinica->agregar_paciente_lista_espera(new paciente("Matias", "00000000-0"));
    // clinica->agregar_paciente_lista_espera(new paciente("Carolina", "19657815-3"));
    // clinica->agregar_paciente_lista_espera(new paciente("Jorge", "13967097-3"));

    clinica->atender_paciente_lista_espera();
    clinica->imprimir_lista_espera();
}