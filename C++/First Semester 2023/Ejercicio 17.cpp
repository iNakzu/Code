/*
Construya una función que reciba como parámetro 4 números reales, la función debe retornar el número menor de los parámetros recibidos
*/

#include <iostream>

float minor(float a, float b, float c, float d)
{
    float min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    if (d < min)
    {
        min = d;
    }
    return min;
}

int main()
{
    float w, x, y, z;
    std::cout << "Digite 4 notas que no sean iguales\n";
    std::cout << "Digite el primer digito: "; std::cin >> w;
    std::cout << "Digite el segundo digito: "; std::cin >> x;
    std::cout << "Digite el tercer digito: "; std::cin >> y;
    std::cout << "Digite el cuarto digito: "; std::cin >> z;
    std::cout << "El numero menor es: " << minor(w, x, y, z) << std::endl;
}