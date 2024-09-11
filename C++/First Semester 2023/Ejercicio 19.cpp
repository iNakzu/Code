/*
Construya una aplicación que lea 4 notas, la aplicación debe decir cual es la nota mas baja, ademas debe devolver el promedio de las 3 mejores notas.
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
    std::cout << "Digite 4 notas que no sean iguales:\n";
    std::cout << "Digite el primer digito: "; std::cin >> w;
    std::cout << "Digite el segundo digito: "; std::cin >> x;
    std::cout << "Digite el tercer digito: "; std::cin >> y;
    std::cout << "Digite el cuarto digito: "; std::cin >> z;
    std::cout << "La nota mas baja es " << minor(w, x, y, z) << std::endl;
    float avg = (w + x + y + z - minor(w, x, y, z)) / 3;
    std::cout << "El promedio de las tres mejores notas es: " << avg << std::endl;
}