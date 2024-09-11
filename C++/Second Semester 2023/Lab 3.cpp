#include <iostream>
#include <string>
#include <queue>
#include <vector>

class VictimaChucky
{
private:
    std::string nombre;
    int id;
    bool vida;
    std::queue<int> porcentaje_sustos;

public:
    VictimaChucky(std::string nombre, int id, std::queue<int> porcentaje_sustos)
    {
        this->nombre = nombre;
        this->id = id;
        this->vida = true;
        this->porcentaje_sustos = porcentaje_sustos;
    }
    std::string get_nombre()
    {
        return nombre;
    }
    int get_id()
    {
        return id;
    }
    void agregar_susto(int magnitud)
    {
        if (magnitud > 0 && magnitud <= 100)
        {
            porcentaje_sustos.push(magnitud);
            std::cout << "Se ha agregado el susto y su magnitud a la cola" << std::endl;
        }
        else
        {
            std::cout << "Numero invalido" << std::endl;
        }
    }
    int calcular_promedio_sustos(VictimaChucky victima)
    {
        int sum = 0;
        std::queue<int> temp = victima.porcentaje_sustos;
        int numero_sustos = temp.size();
        while (!temp.empty())
        {
            sum += temp.front();
            temp.pop();
        }
        return sum / numero_sustos;
    }
    bool se_muere(VictimaChucky victima)
    {
        if (victima.calcular_promedio_sustos(victima) >= 85)
        {
            std::cout << "La victima de nombre " << victima.get_nombre() << " se murio" << std::endl;
            victima.vida = false;
            return true;
        }
        else
        {
            std::cout << "La victima de nombre " << victima.get_nombre() << " no esta muerta" << std::endl;
            victima.vida = true;
            return false;
        }
    }
};

class Pesadilla_Chucky
{
private:
    std::vector<VictimaChucky> victimas;

public:
    void ingresar_victima(VictimaChucky *victima, float primer_susto)
    {
        victima->agregar_susto(primer_susto);
        victimas.push_back(*victima);
    }
    void agregar_susto(int id, float magnitud_susto)
    {
        for (int i = 0; i < victimas.size(); i++)
        {
            if (victimas[i].get_id() == id)
            {
                victimas[i].agregar_susto(magnitud_susto);
            }
        }
    }
    int contar_victimas_muertas()
    {
        int contador = 0;
        for (int i = 0; i < victimas.size(); i++)
        {
            if (victimas[i].se_muere(victimas[i]))
            {
                contador++;
            }
        }
        return contador;
    }
    VictimaChucky *encontrar_victima_mas_aterrada()
    {
        if (victimas.empty())
        {
            return nullptr; // No hay victimas
        }

        VictimaChucky *victima_mas_aterrada = &victimas[0];
        float max_promedio_sustos = victimas[0].calcular_promedio_sustos(victimas[0]);

        for (int i = 1; i < victimas.size(); i++)
        {
            float promedio_sustos = victimas[i].calcular_promedio_sustos(victimas[i]);
            if (promedio_sustos > max_promedio_sustos)
            {
                max_promedio_sustos = promedio_sustos;
                victima_mas_aterrada = &victimas[i];
            }
        }
        return victima_mas_aterrada;
    }
};

int main()
{
}