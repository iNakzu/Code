/*
Crear una clase Fecha con atributos para el día, mes y año de la fecha. Se pide lo
siguiente:

a. Constructor vacío, en donde se debe dejar la fecha 1-1-1900.
b. Constructor que permita inicializar todos los atributos.
c. Método void leer(): permite cambiar la fecha por entrada del usuario.
d. Método void mostrar(): muestra la fecha actual.
e. Método void siguiente(): permite pasar al siguiente día.
f. Método void anterior(): permite pasar al día anterior.
g. Método void Comparar(Fecha x): indica si la fecha actual es la misma, anterior o posterior a D.
*/

#include <iostream>

class Fecha
{
private:
    int day;
    int month;
    int year;

public:
    Fecha() {}
    Fecha(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void leer()
    {
        int d, m, y; // Dia, Mes, Anho
        std::cout << "Ingrese nueva dia -> ";
        std::cin >> d;
        std::cout << "Ingrese nueva mes -> ";
        std::cin >> m;
        std::cout << "Ingrese nueva anho -> ";
        std::cin >> y;
        this->day = d;
        this->month = m;
        this->year = y;
    }
    void mostrar()
    {
        std::cout << "La fecha actual es: " << day << "-" << month << "-" << year << std::endl;
    }
    void siguiente()
    {
    }
    void anterior()
    {
    }
    void Comparar(Fecha x)
    {
    }
};

int main()
{
    Fecha *f1 = new Fecha();
    f1->mostrar();
    f1->leer();
    f1->mostrar();
}