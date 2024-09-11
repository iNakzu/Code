// Ejercicio 1

#include <iostream>

class MisNotas
{
private:
    float notas[10];

public:
    MisNotas()
    {
        for (int i = 0; i < 10; i++)
        {
            notas[i] = 0;
        }
    }

    void agregar_nota(float nota)
    {
        bool espacio_disponible = false;
        int indice_reemplazo = -1; // Índice de la nota a reemplazar si no hay espacio disponible

        for (int i = 0; i < 10; i++)
        {
            if (notas[i] == 0)
            {
                notas[i] = nota;
                espacio_disponible = true;
                std::cout << "La nota número " << i + 1 << " ahora tiene un valor de " << nota << std::endl;
                break;
            }
            else if (notas[i] < nota)
            {
                // Encontramos una nota menor que la nueva nota, la guardamos como posible reemplazo
                indice_reemplazo = i;
            }
        }

        if (!espacio_disponible && indice_reemplazo != -1)
        {
            // Si no hay espacio disponible y encontramos una nota menor, la reemplazamos
            notas[indice_reemplazo] = nota;
            std::cout << "No había espacio disponible. Se reemplazó una nota con valor " << notas[indice_reemplazo] << std::endl;
        }
        else if (!espacio_disponible)
        {
            // Si no hay espacio disponible y todas las notas son mayores, mostramos el mensaje
            std::cout << "Todas las notas son mayores a " << nota << ". La nota no pudo ser agregada." << std::endl;
        }
    }

    float obtener_promedio()
    {
        float sum = 0;
        float count = 0;
        for (int i = 0; i < 10; i++)
        {
            if (notas[i] != 0)
            {
                sum += notas[i];
                count++;
            }
        }
        if (count == 0)
        {
            std::cout << "No hay notas disponibles para calcular el promedio." << std::endl;
        }
        return sum / count;
    }
};

int main()
{
    MisNotas mis_notas;
    mis_notas.agregar_nota(5);
    mis_notas.agregar_nota(10);
    mis_notas.agregar_nota(13);
    std::cout << "El promedio de notas es: " << mis_notas.obtener_promedio() << std::endl;
}