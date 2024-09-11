/*
Hacer una clase para Reloj para controlar la hora, el cual debe tener como atributos la hora, minutos y segundos actuales.
Debe implementar la clase con un constructor, y crear sus setters y getters. Debe además implementar los métodos:

- print(), imprime la hora del reloj en el formato hh:mm:ss.
- comparar(Reloj r), compara la hora con otro reloj e imprime un msg si el reloj está adelantado, atrasado o igual comparado a r.
- sincronizar(Reloj r), se sincroniza el reloj con respecto a r
*/

#include <iostream>

class Reloj
{
private:
    int hour;
    int min;
    int sec;

public:
    Reloj(int hour, int min, int sec)
    {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    void set_hour(int h)
    {
        hour = h;
    }

    int get_hour()
    {
        return hour;
    }

    void set_min(int m)
    {
        min = m;
    }

    int get_min()
    {
        return min;
    }

    void set_sec(int s)
    {
        sec = s;
    }

    int get_sec()
    {
        return sec;
    }

    void print()
    {
        std::cout << "Son las -> " << hour << ":" << min << ":" << sec << std::endl;
    }

    void comparar(Reloj r)
    {
        if (hour < r.hour || (hour == r.hour && min < r.min) || (hour == r.hour && min == r.min && sec < r.sec))
        {
            std::cout << "El reloj está atrasado." << std::endl;
        }
        else if (hour > r.hour || (hour == r.hour && min > r.min) || (hour == r.hour && min == r.min && sec > r.sec))
        {
            std::cout << "El reloj está adelantado." << std::endl;
        }
        else
        {
            std::cout << "El reloj está igual." << std::endl;
        }
    }

    void sincronizar(Reloj r)
    {
        hour = r.hour;
        min = r.min;
        sec = r.sec;
    }
};

int main()
{
    Reloj r1(19, 49, 32);
    Reloj r2(18, 42, 30);

    std::cout << "El reloj numero uno: ";
    r1.print();
    std::cout << "El reloj numero dos: ";
    r2.print();

    std::cout << "\n";

    std::cout << "Comparacion reloj uno con reloj dos: ";
    r1.comparar(r2);

    std::cout << "\n" << std::endl;

    std::cout << "Sincronizando reloj uno con reloj dos. ";
    r1.sincronizar(r2);
    std::cout << "El reloj numero uno: ";
    r1.print();
}