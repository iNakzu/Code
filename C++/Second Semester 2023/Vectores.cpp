#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    nums.push_back(50);
    nums.push_back(60);

    // Eliminar elementos del vector, .begin() parte en 0
    nums.erase(nums.begin());

    // Recorrer un vector como si fuera un arreglo

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << "\n";

    // Recorrer con iterador

    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    std::vector<int> numeros;

    int aux;

    numeros.push_back(11);
    numeros.push_back(5);
    numeros.push_back(-1);
    numeros.push_back(0);
    numeros.push_back(-38);
    numeros.push_back(3);
    numeros.push_back(34);

    for (int i = 0; i < numeros.size(); i++) // Ordenar un vector, <, para mayor a menor y >, para menor a mayor
    {
        for (int j = i + 1; j < numeros.size(); j++)
        {
            if (numeros[i] > numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

    for (int i = 0; i < numeros.size(); i++)
    {
        std::cout << numeros[i] << " ";
    }
}