/*
Enunciado 1:
En el último cyber day el sitio x, trataba de convencer a los clientes para que no
dejasen el carrito abandonado y efectuaran la compra.
la solución era simple, utilizaban una clase llamada carrito que contaba con tres atributos: un vector de enteros
con los montos de los productos del carrito, un atributo entero que corresponde al tipo de cliente que estaba
comprando y un map<int, int> con los descuentos por tipo de cliente.
la llave del map es el tipo de cliente y el contenido el porcentaje de descuento. la clase cuenta con un método
llamado monto_a_pagar() que devuelve el monto a pagar por el cliente en caso que se aplique el descuento por
tipo de cliente y así no abandone el carro.

(20 puntos) en base a lo anterior se pide programar solo el método int monto_a_pagar().
*/

#include <iostream>
#include <vector>
#include <map>

class Carrito // Estos atributos privados de la clase te lo da el enunciado
{
private:
    std::vector<int> monto_compras;
    int tipo_cliente;
    std::map<int, int> descuentos; // Tipo de cliente, Porcentaje %
public:
    int monto_a_pagar()
    {
        int total = 0;

        for (int i = 0; i < monto_compras.size(); i++)
        {
            total += monto_compras[i]; // Esto nos da el monto de la compra sin descuentos
        }

        if (descuentos.find(tipo_cliente) != descuentos.end()) // Si existe un descuento, se aplica
        {
            total -= total * descuentos[tipo_cliente] / 100;
        }
        return total;
    }
};