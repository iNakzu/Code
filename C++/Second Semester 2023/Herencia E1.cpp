/*
Desarrolle un programa de C++ que modele animales y sus sonidos. Para ello, cree una clase abstracta Animal con atributos nombre_cientifico (string), y un constructor para inicializarlos. Esta clase debe contener un metodo virtual puro llamado realizar_sonido(). Derive dos clases, Perro (porcentaje_de_energia) y Gato (numero_de_vidas), que sobrescriban el metodo para mostrar "Wuau!" y "Miau!", respectivamente.
*/

#include <iostream>

class Animal // Clase abstracta
{
protected:
    std::string nombre_cientifico;

public:
    Animal(std::string nombre_cientifico)
    {
        this->nombre_cientifico = nombre_cientifico;
    }
    virtual void realizar_sonido() = 0;
};

class Perro : public Animal
{
private:
    float porcentaje_de_energia;

public:
    Perro(std::string nombre_cientifico, float porcentaje_de_energia) : Animal(nombre_cientifico)
    {
        this->porcentaje_de_energia = porcentaje_de_energia;
    }
    void realizar_sonido() override
    {
        std::cout << "Wuau!" << std::endl;
    }
};

class Gato : public Animal
{
private:
    int numero_de_vidas;

public:
    Gato(std::string nombre_cientifico, int numero_de_vidas) : Animal(nombre_cientifico)
    {
        this->numero_de_vidas = numero_de_vidas;
    }
    void realizar_sonido() override
    {
        std::cout << "Miau!" << std::endl;
    }
};

int main()
{
    Perro *perro = new Perro("Canis lupus familiaris", 100);
    Gato *gato = new Gato("Felis silvestris catus", 7);

    perro->realizar_sonido();
    gato->realizar_sonido();

    Animal *animal = new Gato("Tom", 7); // Polimorfismo, almacenar un objeto de una clase derivada en una variable de tipo de la clase base
    animal->realizar_sonido();

    return 0;
}