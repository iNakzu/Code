/*
Desarrolle un programa que manipule una matriz de enteros 8x8 con las siguientes características:

1.- Tenga una función que permita llenar la matriz con valores aleatorios. Use la función random() para generar números aleatorios (sino lo ha visto investigar).
2.- Función que permita imprimir por pantalla (por filas) la matriz generada.
3.- Función que reciba como parámetro una fila de la matriz e imprima todos los valores de dicha fila
4.- Función que reciba como parámetro una columna y devuelva la suma de todos los valores de dicha columna.
5.- Una función reciba en forma adicional como parámetro un valor ‘X’ y determine si este valor existe en la matriz. Si el valor existe, deberá imprimir todos los elementos que se encuentran en la misma fila del valor encontrado, además imprima la suma de los elementos que están en la misma columna del valor encontrado. Si el valor no existe, deberá imprimir un mensaje apropiado. Importante el valor puede encontrarse 0 ó más veces en la matriz.
6.- Función main(), permita definir la matriz, inicializarla con valores aleatorios (a), imprimirla (b) y aplicar la función del punto (e)
*/

#include <iostream>
#include <cstdlib> // Incluir la biblioteca para la función random()
#include <ctime>   // Incluir la biblioteca para la función time

void fill(int mtz[][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            mtz[i][j] = (std::rand() % 100); // Generar un número aleatorio del 1 al 100
        }
    }
}

void print_matrix(const int mtz[][8])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::cout << mtz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void print_row(const int fila[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << fila[i] << "\t";
    }
    std::cout << "\n";
}

int sum_column(const int mtz[][8], int column)
{
    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += mtz[i][column];
    }
    return sum;
}

// Función para buscar un valor en la matriz
void buscar_valor(int matriz[][8], int value)
{
    bool found = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (matriz[i][j] == value)
            {
                found = true;
                std::cout << "Valor (" << value << ") encontrado en la fila " << i << ": ";
                print_row(matriz[i], 8);
                int sum = sum_column(matriz, j);
                std::cout << "Suma de la columna " << j << ": " << sum << "\n"
                          << std::endl;
            }
        }
    }
    if (!found)
    {
        std::cout << "El valor no existe en la matriz." << std::endl;
    }
}

int main()
{
    int matriz[8][8];

    // Establecer la semilla para generar valores aleatorios
    std::srand(std::time(0));

    fill(matriz); // Llenar la matriz con valores aleatorios

    print_matrix(matriz); // Imprimir la matriz por filas

    std::cout << "\n";

    int row_selected;
    int selected_column;
    std::cout << "Ingrese el número de la fila que desea imprimir (0-7): ";
    std::cin >> row_selected;

    if (row_selected >= 0 && row_selected < 8)
    {
        print_row(matriz[row_selected], 8);
        std::cout << "\n";
    }
    else
    {
        std::cout << "Fila inválida. Ingrese un número de fila válido (0-7).\n" << std::endl;
    }

    std::cout << "Ingrese el número de la columna que desea sumar (0-7): ";
    std::cin >> selected_column;

    if (selected_column >= 0 && selected_column < 8)
    {
        int suma = sum_column(matriz, selected_column);
        std::cout << "La suma de la columna " << selected_column << " es: " << suma << "\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Columna inválida. Ingrese un número de columna válido (0-7).\n" << std::endl;
    }

    buscar_valor(matriz, 0); // Buscamos el valor de 0 en la matriz
    return 0;
}