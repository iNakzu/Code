/*
1.- El Hospital de la comuna ha debido lidiar con las enfermedades respiratorias que afectan a los
niños. Al momento de llegar un paciente una enfermera revisa el nivel de criticidad del niño o
niña que llega y en base a ello opta por dos opciones: pasar el paciente a la lista de espera de
urgencias que tiene un comportamiento FIFO o bien a una lista de avance normal que también
tiene comportamiento FIFO. Siempre se dara prioridad a los pacientes de la lista de espera de
urgencias, aunque cada 5 llamados el próximo llamado debe ser de un paciente normal (salvo
que no exista paciente normal en lista de espera). En base a lo anterior y como una forma de
ayudar a la implementacion computacional del control de las listas de espera se pide:

1.- Defina la estructura de la clase ManejoListaDeEspera que tiene como atributos las dos
listas antes señaladas (de tipo string y que contiene el nombre del paciente), alguna
variable que controle las llamadas y que permita que la lista normal avance cada 5
llamados. Usted debe explicar qué tipo de datos usará por cada lista, explique su uso.
2.- Programe el método void añadir_paciente(string nombre, int criticidad), que recibe un
paciente y lo pasa a la lista de espera correspondiente, donde la criticidad 1 implica
urgente y 0 normal.
3.- Programe el método string llamar_paciente(), que de acuerdo a la estrategia de llamadas
llame al próximo paciente (devuelve su nombre) y lo saca de la lista de espera.
4.- Programe el método void estadistica_espera(), que imprime cuántos pacientes en total
están en espera, cuántos en la lista de urgencia y cuantos en la lista normal.

Ejemplo:

Lista Urgencia Hugo Paco Luis Jaime Laura Cata Laila
Lista Normal Pablo Pedro Juan

En los llamados el primero a a atender será Hugo (1), luego Paco (2), luego Luis (3), luego Jaime
(4), luego Laura (5), el el que sigue será Pablo de la lista normal pues ya se atendieron en forma
seguida 5 pacientes de la lista de Urgencia (el contador de 5 pacientes vuelve a 0), por ende
después de Pablo se atendrá a Cata
*/

#include <queue>
#include <string>
#include <iostream>

/*
class ManejoListaDeEspera {
    private:
        std::queue<std::string> cola_urgencias;
        std::queue<std::string> cola_normal;
        int contador_llamados = 0;

    public:
        void anadir_paciente(std::string nombre, int criticidad) {
            if (criticidad == 1) {
                cola_urgencias.push(nombre);
            } else if (criticidad == 0) {
                cola_normal.push(nombre);
            }
        }
        std::string llamar_paciente() {
            std::string nombre_paciente;
            if (!cola_urgencias.empty() && (contador_llamados < 5 || cola_normal.empty())) {
                nombre_paciente = cola_urgencias.front();
                cola_urgencias.pop();
                contador_llamados++;
            } else if (!cola_normal.empty()) {
                nombre_paciente = cola_normal.front();
                cola_normal.pop();
                contador_llamados = 0;
            }
            return nombre_paciente;
        }
        void estadistica_espera() {
            std::cout << "Total pacientes en espera: " << cola_urgencias.size() + cola_normal.size() << std::endl;
            std::cout << "Pacientes en lista de urgencia: " << cola_urgencias.size() << std::endl;
            std::cout << "Pacientes en lista normal: " << cola_normal.size() << std::endl;
        }
};

int main() {
    ManejoListaDeEspera manejo;

    // Añadir pacientes a las listas
    manejo.anadir_paciente("Paciente Urgencia 1", 1);
    manejo.anadir_paciente("Paciente Normal 1", 0);
    manejo.anadir_paciente("Paciente Urgencia 2", 1);
    manejo.anadir_paciente("Paciente Normal 2", 0);
    manejo.anadir_paciente("Paciente Urgencia 3", 1);
    manejo.anadir_paciente("Paciente Normal 3", 0);
    manejo.anadir_paciente("Paciente Urgencia 4", 1);
    manejo.anadir_paciente("Paciente Normal 4", 0);
    manejo.anadir_paciente("Paciente Urgencia 5", 1);
    manejo.anadir_paciente("Paciente Urgencia 6", 1);

    // Llamar a los pacientes
    for (int i = 0; i < 10; i++) {
        std::cout << "Llamando a: " << manejo.llamar_paciente() << std::endl;
    }

    // Mostrar estadísticas
    manejo.estadistica_espera();

    return 0;
}
*/

/*
2.- Una compañia de Seguros dispone de 3 tipos de seguros: Hogar, Automotriz, Vida. Todo
seguro tiene un número de póliza, un cliente asociado (nombre y rut) y el monto asegurado
Los seguros Hogar pueden proteger contra incendio, terremoto e inundación (puede ser una
combinación de estos). En el caso del seguro Hogar existe un tipo especial que es el seguro
Parcela que tiene como información adicional los metros cuadrados de terreno y el porcentaje
de dicho terreno que tiene plantaciones de árboles nativos.
El seguro Automotriz tiene asociado la patente y año del vehículo
EI seguro Vida tiene asociado el nombre del beneficiario en caso de deceso del asegurado.
1. Escriba el código de cada clase, incluyendo un método imprimir, que muestra el detalle
completo de cada seguro, es decir, todos sus datos. No es necesario implementar los
métodos get y set asociados.
*/

class Seguro
{
protected:
    int numero_poliza;
    std::string nombre_cliente;
    std::string rut_cliente;
    int monto_asegurado;

public:
    Seguro(int numero_poliza, std::string nombre_cliente, std::string rut_cliente, int monto_asegurado)
    {
        this->numero_poliza = numero_poliza;
        this->nombre_cliente = nombre_cliente;
        this->rut_cliente = rut_cliente;
        this->monto_asegurado = monto_asegurado;
    }
    void imprimir()
    {
        std::cout << "Informacion del cliente:"
                  << "\n";
        std::cout << "Nombre: " << nombre_cliente << "\n";
        std::cout << "Rut: " << rut_cliente << "\n";
        std::cout << "Numero de Poliza: " << numero_poliza << "\n";
        std::cout << "Monto Asegurado: $" << monto_asegurado << "\n";
    }
};

class SeguroHogar : public Seguro
{
protected:
    bool incendio;
    bool terremoto;
    bool inundacion;

public:
    SeguroHogar(int numero_poliza, std::string nombre_cliente, std::string rut_cliente, int monto_asegurado, bool incendio, bool terremoto, bool inundacion) : Seguro(numero_poliza, nombre_cliente, rut_cliente, monto_asegurado)
    {
        this->incendio = incendio;
        this->terremoto = terremoto;
        this->inundacion = inundacion;
    }
    void imprimir()
    {
        Seguro::imprimir();
        std::cout << "Protección contra incendio: " << (incendio ? "Sí" : "No") << std::endl;
        std::cout << "Protección contra terremoto: " << (terremoto ? "Sí" : "No") << std::endl;
        std::cout << "Protección contra inundación: " << (inundacion ? "Sí" : "No") << std::endl;
    }
};

class SeguroHogarParcela : public SeguroHogar
{
private:
    int metros_cuadrados_terreno;
    int porcentaje_plantaciones;

public:
    SeguroHogarParcela(int numero_poliza, std::string nombre_cliente, std::string rut_cliente, int monto_asegurado, bool incendio, bool terremoto, bool inundacion, int metros_cuadrados_terreno, int porcentaje_plantaciones) : SeguroHogar(numero_poliza, nombre_cliente, rut_cliente, monto_asegurado, incendio, terremoto, inundacion)
    {
        this->metros_cuadrados_terreno = metros_cuadrados_terreno;
        this->porcentaje_plantaciones = porcentaje_plantaciones;
    }
    void imprimir()
    {
        SeguroHogar::imprimir();
        std::cout << "Metros cuadrados de terreno: " << metros_cuadrados_terreno << std::endl;
        std::cout << "Porcentaje de árboles nativos en el terreno: " << porcentaje_plantaciones << "%" << std::endl;
    }
};

class SeguroAutomotriz : public Seguro
{
private:
    std::string patente_vehiculo;
    std::string anho_vehiculo;

public:
    SeguroAutomotriz(int numero_poliza, std::string nombre_cliente, std::string rut_cliente, int monto_asegurado, std::string patente_vehiculo, std::string anho_vehiculo) : Seguro(numero_poliza, nombre_cliente, rut_cliente, monto_asegurado)
    {
        this->patente_vehiculo = patente_vehiculo;
        this->anho_vehiculo = anho_vehiculo;
    }
    void imprimir()
    {
        Seguro::imprimir();
        std::cout << "Patente del vehículo: " << patente_vehiculo << std::endl;
        std::cout << "Año del vehículo: " << anho_vehiculo << std::endl;
    }
};

class SeguroVida : public Seguro
{
private:
    std::string beneficiario;

public:
    SeguroVida(int numero_poliza, std::string nombre_cliente, std::string rut_cliente, int monto_asegurado, std::string beneficiario) : Seguro(numero_poliza, nombre_cliente, rut_cliente, monto_asegurado)
    {
        this->beneficiario = beneficiario;
    }
    void imprimir()
    {
        Seguro::imprimir();
        std::cout << "Beneficiario en caso de deceso: " << beneficiario << std::endl;
    }
};

int main()
{
    Seguro seguro(8374, "Ignacio", "00000000-0", 300000);
    seguro.imprimir();
    std::cout << "\n";
    SeguroHogarParcela seguro_parcela(4233, "Jorge", "00000000-0", 450000, true, false, true, 34, 77);
    seguro_parcela.imprimir();
}