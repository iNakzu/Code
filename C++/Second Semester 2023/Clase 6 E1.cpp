/*
La clase cuenta_rut tiene los siguientes atributos: int numero, int saldo y char estado. Programe los siguientes métodos de la clase, además del constructor, setters y getters:

- void depositar(int monto): aumenta en monto el saldo de la cuenta.
- void girar(int monto): reduce en monto el saldo de la cuenta. Una cuenta no puede quedar con saldo negativo.
- void imprimir_detalle(): imprime los datos de la cuenta_rut

Además de lo anterior, implemente la función void transferencia(cuenta_rut a, cuenta_rut b, int monto) que permite transferir un monto desde una cuenta A a la B.
Considere nuevamente que una cuenta no puede tener saldo negativo.
*/

#include <iostream>

class Rut
{
private:
    int num;
    int saldo;
    char estado;

public:
    Rut(int num, int saldo, char estado)
    {
        this->num = num;
        this->saldo = saldo;
        this->estado = estado;
    }

    void set_num(int num)
    {
        this->num = num;
    }

    int get_num()
    {
        return num;
    }
    void set_saldo(int saldo)
    {
        this->saldo = saldo;
    }

    int get_saldo()
    {
        return saldo;
    }

    void set_estado(char estado)
    {
        this->estado = estado;
    }

    char get_estado()
    {
        return estado;
    }

    void depositar(int monto)
    {
        saldo += monto;
        std::cout << "Has depositado $" << monto << " a tu cuenta\n"
                  << std::endl;
    }

    void girar(int monto)
    {
        if (saldo >= monto)
        {
            saldo -= monto;
            std::cout << "Has girado $" << monto << " de tu cuenta" << std::endl;
        }
        else
        {
            std::cout << "Saldo insuficiente. No se puede realizar el giro." << std::endl;
        }
    }

    void imprimir_detalle()
    {
        std::cout << "Detalles de cuenta:" << std::endl;
        std::cout << "Numero: " << num << std::endl;
        std::cout << "Saldo: " << saldo << std::endl;
        std::cout << "Estado: " << estado << "\n"
                  << std::endl;
    }
};

void transferencia(Rut &a, Rut &b, int monto)
{
    if (a.get_saldo() >= monto)
    {
        a.girar(monto);
        b.depositar(monto);
        std::cout << "Transferencia exitosa: Se han transferido $" << monto << " de la cuenta " << a.get_num() << " a la cuenta " << b.get_num() << "\n" << std::endl;
    }
    else
    {
        std::cout << "Saldo insuficiente. No se realizar la transferencia." << std::endl;
    }
}

int main()
{
    Rut r1(217309603, 33235, 'O');
    Rut r2(139670973, 145432, 'O');
    r1.imprimir_detalle();
    r2.imprimir_detalle();
    transferencia(r1, r2, 20000);
    r1.imprimir_detalle();
    r2.imprimir_detalle();
}