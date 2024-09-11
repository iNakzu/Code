#include <iostream>

void bubble_sort(float array[15])
{
    float aux;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    std::cout << "Array en orden ascendente" << std::endl;
    for (int i = 0; i < 15; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Array en orden descendiente" << std::endl;
    for (int i = 14; i >= 0; i--)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    float array[15], vlr;
    for (int i = 0; i < 15; i++)
    {
        std::cout << "Digite el valor para x sub " << i << ": ";
        std::cin >> vlr;
        array[i] = vlr;
    }
    std::cout << "\n";
    // Con el arreglo ya definido, utilizamos el metodo burbuja para ordenarlo
    bubble_sort(array);
}