#include <iostream>

void tryhard(float array[11])
{
    float vlr;
    for (int i = 0; i < 11; i++)
    {
        std::cout << "Ingresa el valor del tiempo numero " << i + 1 << ": ";
        std::cin >> vlr;
        array[i] = vlr;
    }
}

void burbuja(float array[11])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[j] > array[j + 1])
            {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Los tiempos de mayor a menor son" << std::endl;
    for (int i = 10; i >= 0; i--)
    {
        std::cout << array[i] << "s ";
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    float arreglo[11];
    std::cout << "Digite los 11 tiempos que se demoro matar a Gwyn\n";
    tryhard(arreglo);
    burbuja(arreglo);

    std::cout << "La mediana de los tiempos es: " << arreglo[5] << std::endl;
    std::cout << std::endl;
    std::cout << "El tiempo menor es de: " << arreglo[0] << std::endl;
    std::cout << std::endl;
    float suma = 0;
    for (int i = 0; i < 11; i++)
    {
        suma += arreglo[i];
    }
    float avg = suma / 11;
    std::cout << "El promedio de los tiempos es: " << avg << std::endl;
}