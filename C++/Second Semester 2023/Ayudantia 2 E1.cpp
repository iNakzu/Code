/*
Se le contrata en un sistema financiero del aclamado Banco balo, aquí se le pide que haga las
siguientes clases:
- Tarjeta que posee un dueño y un saldo.
- Junaeb: que posee un dueño y un saldo y además el método recarga que añade 32000 al
saldo actual.
- RedCompra: que posee un dueño, saldo y método recarga que recibe un monto y lo suma al
saldo actual.
- Crédito: que posee un dueño, saldo, clave, cvv
Debe existir el metodo comprar que descuenta en base al saldo
Debe existir el método mostrar que muestra dueño y saldo
*/

#include <iostream>
#include <string>

class Tarjeta
{
protected:
    std::string nombre;
    int saldo;

public:
    Tarjeta(std::string nombre, int saldo)
    {
        this->nombre = nombre;
        this->saldo = saldo;
    }
    void comprar()
    {
        int compra;
        std::cout << "Ingrese el valor de la compra: $";
        std::cin >> compra;
        if (compra > 0)
        {
            if (compra <= saldo)
            {
                saldo -= compra;
                std::cout << "Se ha realizado la compra satisfactoriamente, su nuevo saldo es: $" << saldo << std::endl;
            }
            else
            {
                std::cout << "Saldo insuficiente" << std::endl;
            }
        }
        else
        {
            std::cout << "Precio invalido" << std::endl;
        }
    }
    void mostrar()
    {
        std::cout << "Nombre del duenho: " << nombre << std::endl;
        std::cout << "Saldo: " << saldo << "\n" << std::endl;
    }
};

class Junaeb : public Tarjeta
{
public:
    Junaeb(std::string nombre, int saldo) : Tarjeta(nombre, saldo) {}

    void recarga()
    {
        saldo += 32000;
        std::cout << "Has recargado con $32.000 tu tarjeta Junaeb" << std::endl;
        std::cout << "Tu nuevo saldo es: $" << saldo << std::endl;
    }
    void mostrar()
    {
        std::cout << "Tipo de tarjeta: Junaeb" << std::endl;
        Tarjeta::mostrar();
    }
};

class RedCompra : public Tarjeta
{
public:
    RedCompra(std::string nombre, int saldo) : Tarjeta(nombre, saldo) {}

    void recarga()
    {
        int recarga;
        std::cout << "Ingrese el monto a recargar en su tarjeta RedCompra: $";
        std::cin >> recarga;
        if (recarga > 0)
        {
            saldo += recarga;
            std::cout << "Recarga exitosa, su nuevo saldo es $" << saldo << std::endl;
        }
        else
        {
            std::cout << "Recarga invalida" << std::endl;
        }
    }
    void mostrar()
    {
        std::cout << "Tipo de tarjeta: RedCompra" << std::endl;
        Tarjeta::mostrar();
    }
};

class Credito : public Tarjeta
{
private:
    int clave;
    int cvv;

public:
    Credito(std::string nombre, int saldo, int clave, int cvv) : Tarjeta(nombre, saldo)
    {
        this->clave = clave;
        this->cvv = cvv;
    }
    void mostrar()
    {
        std::cout << "Tipo de tarjeta: Credito" << std::endl;
        Tarjeta::mostrar();
    }
};

int main()
{
    RedCompra *rc = new RedCompra("Matias", 3500);
    rc->mostrar();
    rc->recarga();
}
