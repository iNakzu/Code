/*
Pregunta 2 - Gestor de Historial de Navegación Web (30 puntos)
Este ejercicio implica implementar un gestor de historial de navegación web, aplicando programación orientada a objetos. Se requiere crear una clase PaginaWeb con atributos como url y titulo, y un método imprimir() para mostrar
estos datos. Además, se debe desarrollar la clase HistorialNavegacion que utiliza dos stacks (historial_anterior y
historial_siguiente) para gestionar las páginas web visitadas, y un atributo paginaActual de tipo PaginaWeb. Los
métodos de navegación como abrir_pagina(), borrar_historial(), volver_pagina_anterior(), ir_pagina_siguiente()
y mostrar_pagina_actual() deben ser implementados. Al cambiar la página actual, se debe imprimir la nueva página
utilizando imprimir() de PaginaWeb.

Detalles de Implementación:
1. abrir_pagina(const PaginaWeb& nueva_pagina): Al abrir una nueva página, la página actual se mueve al stack
historial_anterior. El stack historial_siguiente se vacía, ya que no se puede volver a las páginas "siguientes" después de abrir una nueva página. La nueva_pagina se convierte en la paginaActual.
2. volver_pagina_anterior(): Si el stack historial_anterior no está vacío, la página actual se mueve al stack
historial_siguiente, y la página en la cima de historial_anterior se convierte en la nueva página actual.
3. ir_pagina_siguiente(): Funciona de manera inversa a volver_pagina_anterior(). Si historial_siguiente no está
vacío, la página actual se mueve a historial_anterior y la página en la cima de historial_siguiente se convierte
en la nueva página actual.
4. borrar_historial(): Limpia ambos stacks (historial_anterior y historial_siguiente) y resetea la paginaActual.
Se requiere realizar las siguientes implementaciones:
1. Clase PaginaWeb: Implementar esta clase con atributos url y titulo, un constructor para inicializarlos, un método
imprimir() para mostrar sus atributos, y métodos de acceso (getters). (5 puntos)
2. Clase HistorialNavegacion: Desarrollar esta clase para gestionar el historial de navegación utilizando stacks. Implementar métodos como abrir_pagina() para abrir una nueva página y actualizar el historial, borrar_historial()
para limpiar el historial, volver_pagina_anterior() y ir_pagina_siguiente() para la navegación, y mostrar_pagina_actual()
para mostrar la página actual. Cada acción que cambie la página actual deberá llamar a imprimir() de la página
correspondiente. (25 puntos)

*/

#include <iostream>
#include <stack>
using namespace std;

class PaginaWeb
{
private:
    string url;
    string titulo;

public:
    PaginaWeb(string url, string titulo)
    {
        this->url = url;
        this->titulo = titulo;
    }
    void imprimir()
    {
        cout << "Pagina Web: URL = " << url << ", Titulo = " << titulo << endl;
    }
    // Metodos de acceso (Getters)
    string get_url() const
    {
        return url;
    }
    string get_titulo() const
    {
        return titulo;
    }
};

class HistorialNavegacion
{
private:
    stack<PaginaWeb *> historial_anterior;
    stack<PaginaWeb *> historial_siguiente;
    PaginaWeb *pagina_actual;

public:
    HistorialNavegacion() : pagina_actual(nullptr) {}

    void abrir_pagina(PaginaWeb &nueva_pagina)
    {
        if (pagina_actual != nullptr)
        {
            historial_anterior.push(pagina_actual);
        }
        pagina_actual = &nueva_pagina;
        historial_siguiente = stack<PaginaWeb *>(); // Borra el historial siguiente

        pagina_actual->imprimir();
    }
    void borrar_historial()
    {
        /*
        while (!historial_anterior.empty()) {
            historial_anterior.pop();
        }
        */
        historial_anterior = stack<PaginaWeb*>();
        historial_siguiente = stack<PaginaWeb*>();
    }
    void volver_pagina_anterior()
    {
        if (!historial_anterior.empty())
        {
            historial_siguiente.push(pagina_actual);

            pagina_actual = historial_anterior.top();
            historial_anterior.pop();

            pagina_actual->imprimir();
        }
    }
    void ir_pagina_siguiente()
    {
        if (!historial_siguiente.empty())
        {
            historial_anterior.push(pagina_actual);

            pagina_actual = historial_siguiente.top();
            historial_siguiente.pop();

            pagina_actual->imprimir();
        }
    }
    void mostrar_pagina_actual() const
    {
        pagina_actual->imprimir();
    }
};

/*
Explicación: La clase HistorialNavegacion gestiona dos stacks para el historial de navegación, permitiendo abrir
nuevas páginas, volver a páginas anteriores, ir a páginas siguientes, y borrar el historial completo. Cada cambio
relevante en la navegación provoca la impresión de los detalles de la página actual a través del método imprimir()
de la clase PaginaWeb
*/