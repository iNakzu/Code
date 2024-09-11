/*
Enunciado 2:
Usted ha sido contratado para ayudar en la Biblioteca Nicanor Parra. Dado esto, ha decidido generar un programa
para manejar los libros, que pueden ser Físicos o Virtuales. En esto, se sabe que todo libro, independiente de su
categoría, posee un título (string) y un autor (string) que jamás cambian. Por su parte, los libros físicos poseen un
código de ubicación en biblioteca (int), que podría cambiar en el tiempo, y los libros virtuales poseen una URL
(string) de ubicación. Considerando lo anterior, se pide que:
a) (06 puntos) Genere la clase Libro con su constructor y los atributos y métodos necesarios para este
enunciado.
b) (07 puntos) Utilizando Herencia, genere la clase LibroFisico con su constructor y con los atributos y
métodos que sean necesarios.
c) (07 puntos) Utilizando Herencia, genere la clase LibroVirtual con su constructor y con los atributos y
métodos que sean necesarios.
*/

#include <iostream>

class Libro {
protected:
    const std::string titulo;
    const std::string autor;

public:
    Libro() {} // Constructor vacio
    Libro(std::string titulo, std::string autor) : titulo(titulo), autor(autor) {}
    std::string get_titulo() {
        return titulo;
    }
    std::string get_autor() {
        return autor;
    }
};

class LibroFisico : public Libro {
private:
    int codigo_ubicacion;

public:
    LibroFisico(std::string titulo, std::string autor, int codigo_ubicacion) : Libro(titulo, autor) {
        this->codigo_ubicacion = codigo_ubicacion;
    }
    int get_codigo_ubicacion() {
        return codigo_ubicacion;
    }
    void set_codigo_ubicacion(int codigo_ubicacion) {
        this->codigo_ubicacion = codigo_ubicacion;
    }
};

class LibroVirtual : public Libro {
private:
    std::string url_ubicacion;

public:
    LibroVirtual(std::string titulo, std::string autor, std::string url_ubicacion) : Libro(titulo, autor) {
        this->url_ubicacion = url_ubicacion;
    }
    std::string get_url_ubicacion() {
        return url_ubicacion;
    }
    void set_url_ubicacion(int url_ubicacion) {
        this->url_ubicacion = url_ubicacion;
    }
};