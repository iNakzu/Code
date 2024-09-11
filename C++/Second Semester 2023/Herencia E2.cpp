/*
Desarrolle un programa en C++ para modelar diferentes figuras geometricas y calcular sus propiedades fundamentales. El programa debe contener:

1.- Una clase base Figura sin atributos especificos pero con dos metodos virtuales puros: calcular_area() y calcular_perimetro().

2.- Una clase Cuadrado derivada de Figura con el atributo lado. Implemente los metodos para calcular el area y el perimetro del cuadrado utilizando las siguientes formulas:
    - Area: lado^2
    - Perimetro: 4 * lado

3.- Una clase Circulo derivada de Figura con el atributo radio. Implemente los metodos utilizando las formulas:
    - Area: pi * radio^2
    - Perimetro: 2 * pi * radio

4.- Una clase Triangulo derivada de Figura con los atributos base y altura. A partir de esta clase, derive:

    a. TrianguloRectangulo: Implemente los metodos utilizando:
        - Area: (base * altura) / 2
        - Perimetro: base + altura + sqrt((base)^2 + altura^2)

    b. TrianguloIsosceles: Implemente los metodos utilizando:
        - Area: (base * altura) / 2
        - Lado del triangulo: sqrt((base / 2)^2 + altura^2)
        - Perimetro: base + 2 * lado

5.- En la funcion main, instancie al menos un objeto de cada tipo de figura, calcule y muestre su area y perimetro
*/

#include <iostream>
#include <math.h>
#include <vector>

class Figura
{
public:
    virtual float calcular_area() = 0;
    virtual float calcular_perimetro() = 0;
};

class Cuadrado : public Figura
{
private:
    float lado;

public:
    Cuadrado(float lado)
    {
        this->lado = lado;
    }
    float calcular_area() override
    {
        return pow(lado, 2);
    }
    float calcular_perimetro() override
    {
        return 4 * lado;
    }
};

class Circulo : public Figura
{
private:
    float radio;

public:
    Circulo(float radio)
    {
        this->radio = radio;
    }
    float calcular_area() override
    {
        return M_PI * pow(radio, 2);
    }
    float calcular_perimetro() override
    {
        return 2 * M_PI * radio;
    }
};

class Triangulo : public Figura
{
protected:
    float base;
    float altura;

public:
    Triangulo(float base, float altura)
    {
        this->base = base;
        this->altura = altura;
    }
    float calcular_area() override
    {
        return (base * altura) / 2;
    }
};

class TrianguloRectangulo : public Triangulo
{
public:
    TrianguloRectangulo(float base, float altura) : Triangulo(base, altura) {}

    float calcular_perimetro() override
    {
        float hip = sqrt(pow((base), 2) + pow(altura, 2));
        return base + altura + hip;
    }
};

class TrianguloIsosceles : public Triangulo
{
public:
    TrianguloIsosceles(float base, float altura) : Triangulo(base, altura) {}

    float calcular_perimetro() override
    {
        float hip = sqrt(pow((base / 2), 2) + pow(altura, 2));
        return base + 2 * hip;
    }
};

main()
{
    std::vector<Figura *> figuras;
    figuras.push_back(new Cuadrado(5));
    figuras.push_back(new Circulo(10));
    figuras.push_back(new TrianguloRectangulo(3, 4));
    figuras.push_back(new TrianguloIsosceles(3, 4));

    for (int i = 0; i < figuras.size(); i++)
    {
        std::cout << figuras[i]->calcular_perimetro() << " " << figuras[i]->calcular_area() << std::endl;
    }
}