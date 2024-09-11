#include <iostream>
#include <string>

class Persona
{
private:
    std::string nombre;
    std::string apellido;
    int edad;
    int rut;

public:
    Persona(std::string nombre, std::string apellido, int edad, int rut)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->edad = edad;
        this->rut = rut;
    }

    void set_nombre(std::string nombre)
    {
        this->nombre = nombre; // Setter
    }

    std::string get_nombre()
    {
        return nombre; // Getter
    }

    void set_apellido(std::string apellido)
    {
        this->apellido = apellido; // Setter
    }

    std::string get_apellido()
    {
        return apellido; // Getter
    }

    void set_edad(int edad)
    {
        this->edad = edad; // Setter
    }

    int get_edad()
    {
        return edad; // Getter
    }

    void presentarse()
    {
        std::cout << "Mi nombre es " << nombre << " " << apellido << " tengo " << edad << " y mi rut es " << rut << std::endl;
    }
};

int main()
{
    Persona p1("Ignacio", "Antiguay", 18, 217309603);
    p1.presentarse();
}