#include <iostream>
#include <cstdlib>

static const char caracteres[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "@#*!$%&";

int t = sizeof(caracteres) - 1;

int main()
{
    int longitud = 10;

    srand(time(0));
    for (int k = 0; k < longitud; k++)
    {
        std::cout << caracteres[rand() % ::t];
    }
    std::cout << "\n";
}