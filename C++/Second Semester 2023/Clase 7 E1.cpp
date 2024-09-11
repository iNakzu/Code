/*
Una empresa de correo y encomiendas lo contrata para desarrollar sus sistemas.
Le explican que todo envío posee una dirección de destino y un código (representado por un número entero),
además de los nombres para destinatario y remitente. Le explican, además, que las encomiendas también poseen un peso (el peso debe ser un valor mayor a 0).
Se le pide modelar este sistema, utilizando clases, herencia, constructores, getters y setters.

- Función devolver_envio: Debe generar un envío igual al anterior, pero intercambiando destinatario y remitente, y retornarlo.
- Función mayor_peso: Recibe un arreglo de encomiendas (y su largo) y entrega el destinatario de la encomienda de mayor peso
*/

#include <iostream>
#include <string>

class Envio
{
private:
    std::string destinatario;
    std::string remitente;
    std::string destino;
    int codigo;

public:
    Envio(std::string destinatario, std::string remitente, std::string destino, int codigo)
    {
        this->destinatario = destinatario;
        this->remitente = remitente;
        this->codigo = codigo;
    }

    void set_destinatario(std::string destinatario)
    {
        this->destinatario = destinatario;
    }

    void set_remitente(std::string remitente)
    {
        this->remitente = remitente;
    }

    void set_codigo(int codigo)
    {
        this->codigo = codigo;
    }

    void set_destino(std::string destino)
    {
        this->destino = destino;
    }

    std::string get_destinatario()
    {
        return destinatario;
    }

    std::string get_remitente()
    {
        return remitente;
    }

    std::string get_destino()
    {
        return destino;
    }

    int get_codigo()
    {
        return codigo;
    }

    Envio devolver_envio()
    {
        Envio envio(this->remitente, this->destinatario, this->destino, this->codigo);
        return envio;
    }
};

class Encomienda : public Envio
{
private:
    float peso;

public:
    Encomienda(std::string destinatario, std::string remitente, std::string destino, int codigo, float peso) : Envio(destinatario, remitente, destino, codigo)
    {
        this->peso = peso;
    }

    void set_peso(float peso)
    {
        this->peso = peso;
    }

    float get_peso()
    {
        return peso;
    }
};

std::string mayor_peso(Encomienda encomiendas[], int largo)
{
    float mayor = 0;
    int indice = 0;
    for (int i = 0; i < largo; i++)
    {
        if (encomiendas[i].get_peso() > mayor)
        {
            mayor = encomiendas[i].get_peso();
            indice = i;
        }
    }
    return encomiendas[indice].get_destinatario();
}

int main()
{
    Envio correo("Ignacio", "Matias", "Santiago", 275);
    Encomienda encomienda("Juan", "Pedro", "Santiago", 123, 5.5);
    std::cout << correo.get_destinatario() << std::endl;
    std::cout << correo.get_remitente() << std::endl;
    correo.devolver_envio();
    std::cout << correo.get_destinatario() << std::endl;
    std::cout << correo.get_remitente() << std::endl;
}
