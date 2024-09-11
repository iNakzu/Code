#include <iostream>
#include <string>

class Atleta
{
private:
    std::string pais;
    std::string nombre_atleta;
    float mejor_tiempo_antes_final;
    float tiempo_final;

public:
    Atleta(std::string pais, std::string nombre_atleta, float mejor_tiempo_antes_final)
    {
        this->pais = pais;
        this->nombre_atleta = nombre_atleta;
        this->mejor_tiempo_antes_final = mejor_tiempo_antes_final;
        this->tiempo_final = 0;
    }
    void registrar_tiempo_final(float tiempo)
    {
        this->tiempo_final = tiempo;
    }
    void imprimir()
    {
        std::cout << "Pais de origen: " << pais << std::endl;
        std::cout << "Nombre: " << nombre_atleta << std::endl;
        std::cout << "Mejor tiempo antes de la final: " << mejor_tiempo_antes_final << "s" << std::endl;
        if (tiempo_final != 0)
        {
            std::cout << "Tiempo en la final: " << tiempo_final << "s" << std::endl;
            std::cout << "Porcentaje de su tiempo en la final comparado con su mejor tiempo antes de dicha final: " << (tiempo_final * 100) / mejor_tiempo_antes_final << "%" << std::endl;
        }
        else
        {
            std::cout << "No hay tiempo registrado en la final ya que la carrera no se ha realizado" << std::endl;
        }
    }
    void set_nombre_atleta(std::string nombre_atleta)
    {
        this->nombre_atleta = nombre_atleta;
    }
    float get_tiempo_final()
    {
        return tiempo_final;
    }
    std::string get_nombre_atleta()
    {
        return nombre_atleta;
    }
};

class Carrera
{
private:
    Atleta *atletas[8];

public:
    Carrera()
    {
        for (int i = 0; i < 8; i++)
        {
            atletas[i] = nullptr;
        }
    }
    void agregar_atleta(Atleta *atleta)
    {
        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] == nullptr)
            {
                atletas[i] = atleta;
                std::cout << "Atleta agregado en la posicion " << i + 1 << std::endl;
                return;
            }
        }
        std::cout << "No se pudo agregar el atleta, la carrera ya esta llena" << std::endl;
    }
    void muestra_participantes()
    {
        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] != nullptr)
            {
                std::cout << "\nInformacion del atleta numero " << i + 1 << ":" << std::endl;
                atletas[i]->imprimir();
                std::cout << "\n";
            }
            else
            {
                // std::cout << "Posicion " << i + 1 << " vacia" << std::endl;
            }
        }
    }
    void muestra_ganador()
    {
        bool carrera_hecha = false;
        Atleta *ganador = nullptr;

        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] != nullptr && atletas[i]->get_tiempo_final() != 0)
            {
                carrera_hecha = true;
                break;
            }
        }
        if (carrera_hecha)
        {
            for (int i = 0; i < 8; i++)
            {
                if (atletas[i] != nullptr)
                {
                    if (ganador == nullptr || atletas[i]->get_tiempo_final() < ganador->get_tiempo_final())
                    {
                        ganador = atletas[i];
                    }
                }
            }
            std::cout << "Nombre del ganador de la carrera: " << ganador->get_nombre_atleta() << std::endl;
        }
        else
        {
            std::cout << "Carrera aun no realizada" << std::endl;
        }
    }
};

int main()
{
    // std::cout << "Ola" << std::endl;
    Atleta *a1 = new Atleta("Chile", "Ignacio", 59);
    Atleta *a2 = new Atleta("Argentina", "Federico", 53);
    Atleta *a3 = new Atleta("Colombia", "Ernesto", 54);
    a1->registrar_tiempo_final(32);
    a2->registrar_tiempo_final(31);
    a3->registrar_tiempo_final(30);

    Carrera *carrera = new Carrera();
    carrera->agregar_atleta(a1);
    carrera->agregar_atleta(a2);
    carrera->agregar_atleta(a3);

    carrera->muestra_participantes();
    carrera->muestra_ganador();
}