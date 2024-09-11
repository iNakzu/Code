/*
Cree una función denominada void cuanto_me_falta(float presentación) que imprime cuánto necesita un alumno para salvarse de la asignatura a fin de semestre.
La función recibe como parámetro la nota de presentación y devuelve la nota que debe sacarse en el examen, pero considerando las siguientes reglas:

1.- Si su nota de presentación >= 5 le indica que está eximido
2.- Si su nota de presentación < 3.5 le dice que está reprobado por reglamento
3.- Si su nota es mayor o igual a 3.5 y menor a 5, calcula la nota que necesita considerando que: final = (presentación * 0.7) + (examen * 0,3)
*/

#include <iostream>

void cuanto_me_falta(float np)
{
    if (np >= 5)
    {
        std::cout << "Estas eximido del ramo" << std::endl;
    }
    else if (np >= 3.5 && np < 5)
    {
        float notaExamen = (4 - np * 0.7) / 0.3;
        std::cout << "Debes dar examen para aprobar el ramo" << std::endl;
        std::cout << "Para aprobar tienes que sacarte un " << notaExamen << std::endl;
    }
    else
    {
        std::cout << "Reprobaste el ramo" << std::endl;
    }
}

int main()
{
    float nota_presentacion;
    std::cout << "Digite su nota de presentacion: ";
    std::cin >> nota_presentacion;
    cuanto_me_falta(nota_presentacion);
}
