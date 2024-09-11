/*
Cree la función booleana “es_divisible”, que recibe como parámetros dos números enteros y verifica si son divisibles entre sí.
De serlo, retorna un valor verdadero, en caso contrario retorna falso.
Luego, implemente la función en su función main, de forma que dado el valor que retorna la función “es_divisible”, imprima “los números son divisibles” o “los números no son divisibles”.
*/

#include <iostream>
using namespace std;

bool es_divisible(int a, int b)
{
    if (a % b == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int num, num_two;
    cout << "Ingrese 2 digitos para ver si son divisibles: " << endl;
    cout << "1er digito: "; cin >> num;
    cout << "2do digito: "; cin >> num_two;
    if (es_divisible(num, num_two))
    {
        cout << "Los numeros son divisibles" << endl;
    }
    else
    {
        cout << "Los numeros no son divisibles" << endl;
    }
    return 0;
}