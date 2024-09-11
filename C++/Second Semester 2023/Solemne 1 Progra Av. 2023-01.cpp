/*
Pregunta 1 (30 pts)
Cómo parte de su colaboración en los próximos juegos panamericanos STGO 2023, se le ha pedido programar una clase llamada Pais,
la cual cuenta con 5 atributos: nombre del país, oro (cantidad de medallas de oro), plata (cantidad de medallas de plata),
bronce (cantidad de medallas de bronce), participaciones (cantidad de eventos deportivos en los que el país ha participado).
Considerando la clase solicitada usted debe programar lo siguiente:

    a) (06 puntos) La declaración de la clase País junto con la definición de sus atributos
    b) (06 puntos) El constructor con el o los parámetros necesarios para la inicialización del País
    c) (08 puntos) El método void agregarPartipaciones(int oro, int plata, int bronce, int ninguna) que permite sumar las medallas de oro,
    plata o bronce que va obteniendo el país y la cantidad de participaciones totales en los panamericanos.
    Considere que la variable "ninguna" significa que en esa cantidad de disciplinas no se obtuvo medalla.
    Ejemplo: agregarPartipaciones(0, 2, 3, 5) implicaría que se suma al medallero (a cada tipo de medalla) del país:
    0 de oro, 2 de plata, 3 de bronce. Además, se consideran 5 participaciones sin medalla,
    lo que sumaría 10 participaciones (las 5 medallas y las 5 sin medalla) al total de participaciones que ha tenido el país.
    d) (10 puntos) El método void estadísticas() del país que imprime:
        1. Total de competencias en las que ha participado
        2. Total de medallas de oro, plata, bronce
        3. Porcentaje de competencias en las que obtuvo medalla de oro

Asuma que los métodos “get” y “set” para cada atributo ya existen (no es necesario programarlos).
Ej.: getMedallasOro() retornaría la cantidad de medallas de oro.

Pregunta 2 (30 pts)
Continuando con su apoyo a los próximos juegos panamericanos se le ha encomendado ahora
manejar el medallero por países. Asumiendo que ya existe la clase Pais (si no contestó la
pregunta anterior, no es problema, puede usar la clase), usted debe definir una clase llamada
Panamericanos.
La clase Panamericanos se compone de un arreglo de 41 objetos del tipo Pais, para esta clase
se pide:

    a) (06 puntos) La declaración de la clase Panamericanos junto con la definición de su(s)
    atributo(s).
    b) (06 puntos) El constructor que inicializa el arreglo.
    c) (06 puntos) El método agregarPais que recibe como parámetro un objeto tipo Pais y lo
    agrega al arreglo. Debe validar que el país no haya sido ingresado con anticipación y que
    exista espacio para agregarlo.
    d) (06 puntos) El método void imprimir() que imprime las estadísticas de cada país.
    e) (06 puntos) El método void mayorOro() que busca el país que obtuvo la mayor cantidad
    de medallas de oro, el método debe imprimir el nombre del país y la cantidad de medallas
    de oro obtenidas
*/

#include <iostream>
#include <string>

class Pais
{
private:
    std::string nombre;
    int oro;
    int plata;
    int bronce;
    int participaciones;

public:
    Pais(std::string nombre, int oro, int plata, int bronce, int participaciones)
    {
        this->nombre = nombre;
        this->oro = oro;
        this->plata = plata;
        this->bronce = bronce;
        this->participaciones = participaciones;
    }
    Pais(std::string nombre)
    {
        this->nombre = nombre;
        this->oro = 0;
        this->plata = 0;
        this->bronce = 0;
        this->participaciones = 0;
    }

    std::string get_nombre()
    {
        return nombre;
    }

    int get_oro()
    {
        return oro; // Setters que no son necesarios en la solemne escrita a mano
    }

    void agregar_partipaciones(int oro, int plata, int bronce, int ninguna)
    {
        this->oro += oro;
        this->plata += plata;
        this->bronce += bronce;
        this->participaciones += oro + plata + bronce + ninguna;
    }
    void estadisticas()
    {
        std::cout << "Nombre del pais: " << nombre << std::endl; // Linea no necesaria
        std::cout << "Total de competencias en las que ha participado: " << participaciones << std::endl;
        std::cout << "Total de medallas de oro: " << oro << std::endl;
        std::cout << "Total de medallas de plata: " << plata << std::endl;
        std::cout << "Total de medallas de bronce: " << bronce << std::endl;
        std::cout << "Porcentaje de competencias en las que obtuvo medalla de oro: " << float(oro) * 100 / participaciones << "%\n" << std::endl;
    }
};

class Panamericanos
{
private:
    Pais *paises[41];

public:
    Panamericanos()
    {
        for (int i = 0; i < 41; i++)
        {
            this->paises[i] = nullptr;
        }
    }
    bool agregar_pais(Pais *pais)
    {
        for (int i = 0; i < 41; i++)
        {
            if (paises[i] != nullptr)
            {
                if (paises[i]->get_nombre() == pais->get_nombre())
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < 41; i++)
        {
            if (paises[i] == nullptr)
            {
                paises[i] = pais;
                return true;
            }
        }
        return false;
    }
    void imprimir()
    {
        for (int i = 0; i < 41; i++)
        {
            if (paises[i] != nullptr)
            {
                paises[i]->estadisticas();
            }
        }
    }
    void mayor_oro()
    {
        Pais *pais_mayor;
        for (int i = 0; i < 41; i++)
        {
            if (paises[i] != nullptr)
            {
                pais_mayor = paises[i];
            }
        }

        for (int i = 0; i < 41; i++)
        {
            if (paises[i] != nullptr)
            {
                if (pais_mayor->get_oro() < paises[i]->get_oro())
                {
                    pais_mayor = paises[i];
                }
            }
        }
        std::cout << "Nombre del pais que obtuvo la mayor cantidad de medallas de oro: " << pais_mayor->get_nombre() << std::endl;
        std::cout << "Cantidad de medallas de oro: " << pais_mayor->get_oro() << std::endl;
    }
};

int main()
{ // Se hace una funcion main solo para verificar que el codigo del ejercicio funciona
    Pais *p1 = new Pais("Chile", 7, 3, 4, 15);
    Pais *p2 = new Pais("Peru", 6, 1, 0, 15);
    Pais *p3 = new Pais("Ecuador", 3, 2, 4, 15);
    Pais *p4 = new Pais("Argentina", 1, 2, 3, 15);
    Pais *p5 = new Pais("Bolivia", 0, 0, 0, 15);
    Panamericanos *panamericanos = new Panamericanos();
    panamericanos->agregar_pais(p1);
    panamericanos->agregar_pais(p2);
    panamericanos->agregar_pais(p3);
    panamericanos->agregar_pais(p4);
    panamericanos->agregar_pais(p5);
    panamericanos->imprimir();
    panamericanos->mayor_oro();
}