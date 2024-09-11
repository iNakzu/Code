#include <iostream>
#include <vector> // Libreria necesaria para el uso de vectores

/*
    Los vectores son arreglos dinamicos, son del tipo LIFO (Last in First Out)
    Metodos mas usados:
        size(): retorna el tamaño del vector.
        empty(): retorna true si el vector está vacío, false en caso contrario.
        at(): accede a un elemento, también puede ser con [].
        front(): accede al primer elemento (posición [0]).
        back(): accede al último elemento (posición [n-1]).
        push_back(): agrega un elemento al final.
        pop_back(): elimina el último elemento.
        erase(posición): elimina un elemento. La posición es un iterador.
        clear(): elimina el contenido del vector.
*/

/*
Ejercicio 1:
Usando vectores en un main:
    a. Crear un vector que contenga los múltiplos de 3 entre 100 y 150.
    b. Usando un nuevo ciclo, recorra el vector e imprima el contenido.
*/

// int main() {
//     std::vector<int> vect;

//     for (int i = 100; i < 150; i++) {
//         if (i % 3 == 0) {
//             vect.push_back(i);
//         }
//     }

//     for (int i = 0; i < vect.size(); i++) {
//         std::cout << "Valor en posicion numero [" << i << "]: " << vect[i] << std::endl;
//     }
// }

/*
Ejercicio 2:
Crear y llenar un vector con 6 valores reales ingresados por el usuario.
Recorra el vector e imprima el mayor y menor valor. Elimine el contenido
del vector a excepción de estos dos valores.
*/

int main()
{
    std::vector<int> vect;

    for (int i = 1; i <= 6; i++)
    {
        int input;
        std::cout << "Ingrese el valor para la posicion numero " << i << ": ";
        std::cin >> input;
        vect.push_back(input);
    }

    int highest = vect[0];
    int lowest = vect[0];

    for (int i = 1; i < vect.size(); i++)
    {
        if (vect[i] > highest)
        {
            highest = vect[i];
        }
        else if (vect[i] < lowest)
        {
            lowest = vect[i];
        }
    }
    std::cout << "Valor mas alto del vector: " << highest << std::endl;
    std::cout << "Valor mas bajo del vector: " << lowest << std::endl;

    // Eliminamos el contenido del vector excepto el mayor y menor valor
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] != highest && vect[i] != lowest)
        {
            vect.erase(vect.begin() + i);
            i--; // Ajustamos el índice debido a la eliminación
        }
    }

    // Imprimimos los valores restantes en el vector
    std::cout << "Valores restantes en el vector: ";
    for (double valor : vect)
    {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}
