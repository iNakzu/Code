#include <iostream>
#include <map> // Libreria necesaria para el uso de mapas
#include <vector>
using namespace std;

/*
    Es un diccionario (ordenado por clave), el cual asocia un elemento a una llave.
    ● Dicho ordenamiento se debe a un método comparador.
    ● El acceso a los elementos se hace mediante la llave o mediante iteradores.
    Para poder crear un contenedor del tipo map, se define: map<tipo_dato,tipo_dato> nombre_var; (el primero es la clave, y el segundo el contenido)

    Metodos mas importantes:
        ● size(): retorna el tamaño del map.
        ● empty(): retorna true si el map está vacío, false en caso contrario.
        ● erase(): elimina un elemento
        ● insert(): agrega un elemento
        ● find(): busca un elemento y retorna un iterador
        Para el iterador:
        ● begin(): retorna el iterador al principio
        ● end(): retorna el iterador al final
*/

/*
Ejercicio 1: Crear un mapa que tenga como clave el RUT de una persona y el valor sea la edad. En el programa debe:
● Ingresar 5 tuplas en un main.
● Determinar el promedio de las edades.
● Imprimir todo el contenido del mapa.
● Buscar un rut ingresado por el usuario, y eliminar dicho dato.
*/
