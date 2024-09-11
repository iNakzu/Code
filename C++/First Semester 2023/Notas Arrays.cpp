#include <iostream>
using namespace std;

void leer_notas(float array[5])
{
  for (int i = 0; i < 5; i++)
  {
    cout << "Ingrese una nota del 1 al 7: ";
    cin >> array[i];
    while (array[i] < 1 || array[i] > 7)
    {
      cout << "Nota invalida. Ingrese una nota del 1 al 7: ";
      cin >> array[i];
    }
  }
}

void imprimir_rango_notas(float array[5])
{
  int rojos = 0;
  int cuatros = 0;
  int sobreseis = 0;

  for (int i = 0; i < 5; i++)
  {
    if (array[i] < 4)
    {
      rojos++;
    }
    else if (array[i] < 5.9)
    {
      cuatros++;
    }
    else
    {
      sobreseis++;
    }
  }
  cout << "Total de rojos: " << rojos << endl;
  cout << "Total de 4 y 5.9: " << cuatros << endl;
  cout << "Sobre 6: " << sobreseis << endl;
}

void promedio(float array[5])
{
  float sum = 0;
  for (int i = 0; i < 5; i++)
  {
    sum += array[i];
  }
  cout << "El promedio de notas es: " << sum / 5 << std::endl;
}

int main()
{
  float notas[5];
  leer_notas(notas);
  cout << endl;
  promedio(notas);
  imprimir_rango_notas(notas);
}