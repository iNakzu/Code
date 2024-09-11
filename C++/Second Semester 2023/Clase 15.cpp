/*
Ejercicio Extra 1:
Para el próximo período de inscripción académica, los profesores de Programación Avanzada crearon una clase en C++ para
guardar la información de los alumnos que se inscriben y al mismo tiempo controlar los cupos por sección.

class Secciones{
private:
map<string,int> cupos_seccion;
map<string, vector<string> > alumnos_seccion;
}

El map cupos_seccion guarda la información del código de la sección y la cantidad de cupos de ésta. El map alumnos_seccion
guarda la información, por sección, de los alumnos identificados por su rut (incluyendo guión y dígito verificador). Cada rut es
agregado en el vector validándose que no sobrepase el cupo de la sección. En base a lo anterior, se pide programar los
siguientes métodos:

● void agregar_seccion(string codseccion, int cupos_seccion) : Agrega una nueva sección (código y cupos) verificando que
la sección no se encuentre repetida.
● bool agregar_alumno(string codseccion, string rut alumno) : Agrega un nuevo alumno a la sección devolviendo true si
pudo hacerlo, false en caso contrario (debe validar cupos y existencia de sección).
● impimir_lista(string codseccion)}: Imprime la lista de alumnos (su rut) inscritos en una sección. Al finalizar la impresión
debe indicar cuántos cupos quedan disponibles en cada sección.
*/

#include <iostream>
#include <map>
#include <vector>

class Secciones
{
private:
    std::map<std::string, int> cupos_seccion;
    std::map<std::string, std::vector<std::string>> alumnos_seccion;

public:
    void agregar_seccion(std::string codseccion, int cupos)
    {
        if (cupos_seccion.find(codseccion) == cupos_seccion.end())
        {
            cupos_seccion[codseccion] = cupos;
            alumnos_seccion[codseccion] = std::vector<std::string>();
        }
    }

    bool agregar_alumno(std::string codseccion, std::string rut)
    {
        if (cupos_seccion.find(codseccion) != cupos_seccion.end() && cupos_seccion[codseccion] > 0)
        {
            alumnos_seccion[codseccion].push_back(rut);
            cupos_seccion[codseccion]--;
            return true;
        }
        return false;
    }

    void imprimir_lista(std::string codseccion)
    {
        if (alumnos_seccion.find(codseccion) != alumnos_seccion.end())
        {
            for (const auto &rut : alumnos_seccion[codseccion])
            {
                std::cout << rut << std::endl;
            }
            std::cout << "Cupos disponibles: " << cupos_seccion[codseccion] << std::endl;
        }
    }
};

/*
Ejercicio Extra 2:
Una agencia de viajes requiere implementar un sistema en donde, a través del
rut, se pueda acceder a todas las capitales que desea visitar una persona. Se
debe hacer un menú con lo siguiente:

● Agregar una persona.
● Agregar una capital a visitar por una persona.
● Para una capital en específica, contar el número de personas que desean visitar ese lugar.

Debe utilizar mapas y las estructuras que estime convenientes.
*/

class Agencia
{
private:
    std::map<std::string, std::vector<std::string>> personas;
    std::map<std::string, std::vector<std::string>> capitales;

public:
    void agregar_persona(std::string rut)
    {
        personas[rut] = std::vector<std::string>();
    }

    void agregar_capital(std::string rut, std::string capital)
    {
        if (personas.find(rut) != personas.end())
        {
            personas[rut].push_back(capital);
            capitales[capital].push_back(rut);
        }
    }

    int contar_personas(std::string capital)
    {
        if (capitales.find(capital) != capitales.end())
        {
            return capitales[capital].size();
        }
        return 0;
    }
};

/*
Ejercicio Extra 3:
Una solución de registro de notas maneja un map para almacenar un número de notas por cada rut de
estudiante:

map<string, stack<float> > rut_notas;

La forma visual del mapa podría ser por ejemplo la siguiente, en donde esta en negrita el string con la
llave de rut y los valores a la derecha estarían contenidos en la cola asociada a dicha llave:\

1-9   6;4.5;1.5;5
2-7   2;5.5;2
3-5   7;7;2.8

Cree una función void agregar_nota(string rut, float nota), que agrega una nota al map descrito
anteriormente. Debe controlarse una restricción en el ingreso y es que un alumno no puede tener
más de 4 notas, si ello ocurre, debe enviar el mensaje “Excede el máximo de notas”
*/

#include <stack>

class Registro
{
private:
    std::map<std::string, std::stack<float>> rut_notas;

public:
    void agregar_nota(std::string rut, float nota)
    {
        if (rut_notas[rut].size() < 4)
        {
            rut_notas[rut].push(nota);
        }
        else
        {
            std::cout << "Excede el máximo de notas" << std::endl;
        }
    }
};