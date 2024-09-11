/*
Enunciado 3:
Considere que un Librero es una colección de Libros. Asumiendo que existe la clase Libro con los métodos
get_titulo() y get_autor(), que retorna el nombre del libro y el nombre del autor del libro (ambos string)
respectivamente, se pide que genere:
a) (05 puntos) La clase Librero que se compone de un nombre (string) y dirección (string) que jamás
cambian y de un vector de Libros que comienza vacío.
b) (05 puntos) El método ingresar_libro(Libro *L) de la clase Librero que permite ingresar un libro al vector
de libros siempre y cuando dicho libro no esté previamente ingresado. Si el libro es ingresado o ya se
encuentra en el vector, lo deberá señalar con un mensaje acorde a la situación.
c) (05 puntos) El método sacar_libro(string titulo) que elimina del vector el libro cuyo título coincide con
el parámetro del método. Si el libro es retirado o no se encuentra en el vector, lo deberá señalar con un
mensaje acorde a la situación.
d) (05 puntos) El método imprimir_libros_del_autor(string autor) que imprime el título de todos los libros
del autor cuyo nombre coincide con el parámetro del método. Asuma que, esn este caso, siempre habrá
uno o más libros que pertenezcan al autor.
*/

#include <iostream>
#include <vector>

class Libro
{ // !Codigo de la pregunta anterior
protected:
    const std::string titulo;
    const std::string autor;

public:
    Libro() {} // Constructor vacio
    Libro(std::string titulo, std::string autor) : titulo(titulo), autor(autor) {}
    std::string get_titulo()
    {
        return titulo;
    }
    std::string get_autor()
    {
        return autor;
    }
};

class LibroFisico : public Libro
{
private:
    int codigo_ubicacion;

public:
    LibroFisico(std::string titulo, std::string autor, int codigo_ubicacion) : Libro(titulo, autor)
    {
        this->codigo_ubicacion = codigo_ubicacion;
    }
    int get_codigo_ubicacion()
    {
        return codigo_ubicacion;
    }
    void set_codigo_ubicacion(int codigo_ubicacion)
    {
        this->codigo_ubicacion = codigo_ubicacion;
    }

}; // !Codigo de la pregunta anterior

class LibroVirtual : public Libro
{
private:
    std::string url_ubicacion;

public:
    LibroVirtual(std::string titulo, std::string autor, std::string url_ubicacion) : Libro(titulo, autor)
    {
        this->url_ubicacion = url_ubicacion;
    }
    std::string get_url_ubicacion()
    {
        return url_ubicacion;
    }
    void set_url_ubicacion(int url_ubicacion)
    {
        this->url_ubicacion = url_ubicacion;
    }
};

class Librero
{
private:
    const std::string nombre;
    const std::string direccion;
    std::vector<Libro *> libros;

public:
    Librero(std::string nombre, std::string direccion) : nombre(nombre), direccion(direccion) {}
    void ingresar_libro(Libro *l)
    {
        for (int i = 0; i < libros.size(); i++)
        { // Recorrer el  vector y verificar si existe el libro
            if (libros[i]->get_titulo() == l->get_titulo())
            {
                std::cout << "Este libro ya existe!" << std::endl;
                return;
            }
        }
        libros.push_back(l);
        std::cout << "Libro ingresado!" << std::endl;
    }
    void sacar_libro(std::string titulo)
    {
        for (int i = 0; i < libros.size(); i++)
        { // Recorrer el vector
            if (libros[i]->get_titulo() == titulo)
            {                                     // Si se encuentra el libro, lo elimina del vector
                libros.erase(libros.begin() + i); // Se hace con el iterador que comienza en 0 + i
                std::cout << "Se saco el libro del librero" << std::endl;
                return;
            }
        }
        std::cout << "No se encontro el libro en el librero" << std::endl;
    }
    void imprimir_libros_del_autor(std::string autor)
    {
        for (int i = 0; i < libros.size(); i++)
        { // Recorrer nuevamente el vector
            if (libros[i]->get_autor() == autor)
            { // Si existe un libro de este autor
                std::cout << libros[i]->get_titulo() << std::endl;
            }
        }
    }
};
