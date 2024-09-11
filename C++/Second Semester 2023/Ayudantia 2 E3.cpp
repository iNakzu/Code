/*
El reconocido restaurant “Ratatouille” necesita su ayuda para poder organizar a los
empleados y ha entregado la siguiente
información:
- Un trabajador tiene las características de: nombre y sueldo.
- Los trabajadores se dividen en dos tipos principales: chef y camarero.
- Los chefs tienen como característica principal el plato que se dedican a cocinar:
desayuno, almuerzo u once. Mientras que los camareros cuentan con el atributo del
número de mesas que han atendido durante el día y la propina acumulada.
- Cree las clases y métodos get/set necesarios. Considere la utilización de herencia.
*/

#include <iostream>
#include <string>

class Trabajador
{
protected:
    std::string nombre;
    int sueldo;

public:
    Trabajador(std::string nombre, int sueldo)
    {
        this->nombre = nombre;
        this->sueldo = sueldo;
    }
    std::string get_nombre()
    {
        return nombre;
    }
    int get_sueldo()
    {
        return sueldo;
    }
    void set_nombre(std::string nombre)
    {
        this->nombre = nombre;
    }
    void set_sueldo(int sueldo)
    {
        this->sueldo = sueldo;
    }
};

class Chef : public Trabajador
{
private:
    std::string plato;

public:
    Chef(std::string nombre, int sueldo, std::string plato) : Trabajador(nombre, sueldo)
    {
        this->plato = plato;
    }
};

class Camarero : public Trabajador
{
private:
    int numero_mesas, propina_acumulada;

public:
    Camarero(std::string nombre, int sueldo, int numero_mesas, int propina_acumulada) : Trabajador(nombre, sueldo)
    {
        this->numero_mesas = numero_mesas;
        this->propina_acumulada = propina_acumulada;
    }
};

int main()
{
    Chef *ch1 = new Chef("Juan", 500000, "Almuerzo");
    Camarero *ca1 = new Camarero("Pedro", 300000, 10, 10000);
}