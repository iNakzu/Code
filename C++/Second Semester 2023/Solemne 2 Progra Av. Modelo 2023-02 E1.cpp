/*
Pregunta 1 - Sistema de Gestión de Contenidos Multimedia (30 puntos)
Este ejercicio requiere la implementación de un sistema de gestión de contenidos multimedia utilizando el paradigma
de la programación orientada a objetos. Se debe crear una clase base Multimedia para representar contenidos multimedia
generales, con atributos como título y autor, y un método imprimir() para mostrar estos datos. A partir de esta, se
derivarán clases como Video, Audio y Podcast, cada una con atributos únicos y un método imprimir() propio: Video
con duración y resolución (ejemplo: 1080p, 4K), Audio con duración y si es estéreo o no, y Podcast con tema principal y
número de episodios. Además, se desarrollará una clase ReproductorMultimedia que gestione un vector de Multimedia
e incluya métodos como reproducir(), siguiente(), anterior() y volver_al_principio() para interactuar con los
contenidos. El método reproducir() utilizará el método imprimir() del contenido actual para mostrar sus detalles.

Se requiere realizar las siguientes implementaciones:
1. Clases Derivadas (Video, Audio, Podcast): Implementar estas clases derivadas de la clase Multimedia, cada una
con sus propios atributos y un método imprimir() que muestre los detalles relevantes, además de los datos de la
clase base. (5 puntos)
2. Clase ReproductorMultimedia: Desarrollar esta clase para gestionar un vector de objetos tipo Multimedia. Implementar los métodos reproducir() para mostrar los detalles del contenido actual, siguiente() para avanzar al
siguiente contenido (volviendo al primero si se encuentra en el último), anterior() para retroceder al contenido
previo (yendo al último si se encuentra en el primero), y volver_al_principio() para regresar al primer contenido
del vector. (25 puntos)
*/

#include <iostream>
#include <vector>
using namespace std;

class Multimedia
{
protected:
    string titulo, autor;

public:
    Multimedia(string titulo, string autor)
    {
        this->titulo = titulo;
        this->autor = autor;
    }
    virtual void imprimir()
    {
        cout << " Titulo : " << titulo << ", Autor : " << autor << endl;
    }
};

class Video : public Multimedia
{
private:
    float duracion;
    string resolucion;

public:
    Video(string titulo, string autor, float duracion, string resolucion) : Multimedia(titulo, autor)
    {
        this->duracion = duracion;
        this->resolucion = resolucion;
    }
    void imprimir() override
    {
        Multimedia::imprimir();
        cout << "Duracion : " << duracion << " minutos , Resolucion : " << resolucion << endl;
    }
};

class Audio : public Multimedia
{
private:
    float duracion;
    bool estereo;

public:
    Audio(string titulo, string autor, float duracion, bool estereo) : Multimedia(titulo, autor)
    {
        this->duracion = duracion;
        this->estereo = estereo;
    }
    void imprimir() override
    {
        Multimedia::imprimir();
        cout << "Duracion : " << duracion << " minutos , Stereo : " << (estereo ? "Si" : "No") << endl;
    }
};

class Podcast : public Multimedia
{
private:
    string tema_principal;
    int numero_episodios;

public:
    Podcast(string titulo, string autor, string tema_principal, int numero_episodios) : Multimedia(titulo, autor)
    {
        this->tema_principal = tema_principal;
        this->numero_episodios = numero_episodios;
    }
    void imprimir() override
    {
        Multimedia::imprimir();
        cout << " Tema : " << tema_principal << ", Numero de episodios : " << numero_episodios << endl;
    }
};

class ReproductorMultimedia
{
private:
    vector<Multimedia *> contenidos;
    int contenido_actual = 0; // Indice del contenido actual en reproduccion

public:
    ReproductorMultimedia(int contenido_actual) : contenido_actual(0) {}
    void agregar_contenido(Multimedia *contenido)
    {
        contenidos.push_back(contenido);
    }
    void reproducir()
    {
        if (!contenidos.empty())
        {
            contenidos[contenido_actual]->imprimir();
        }
    }
    void siguiente()
    {
        if (!contenidos.empty())
        {
            contenido_actual = (contenido_actual + 1) % contenidos.size();
            reproducir();
        }
    }
    void anterior()
    {
        if (!contenidos.empty())
        {
            contenido_actual = (contenido_actual == 0) ? contenidos.size() - 1 : contenido_actual - 1;
            reproducir();
        }
    }
    void volver_al_principio()
    {
        if (!contenidos.empty())
        {
            contenido_actual = 0;
            reproducir();
        }
    }
};