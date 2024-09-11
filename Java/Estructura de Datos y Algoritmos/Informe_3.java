/*
    Luego de su exitosa aplicación anterior, inversores de todas las partes del mundo quieren copiarle su gran
    idea y crear un reproductor para competirle a usted. Para poder diferenciarse, nuevamente acude al poderoso
    conocimiento de su ramo favorito ”Estructura de datos y algoritmos” y pensó en desarrollar un buscador de
    canciones para su aplicación.
    Este laboratorio consiste entonces en la implementación de un buscador para su aplicación implementado
    sobre un árbol y diferentes métodos de ordenamiento.
    Se debe usar, al igual que el laboratorio anterior, una clase Canción.
    Para poder funcionar debe implementar los siguientes métodos:
    
        • Agregar cancion: Recibe una canción y la agrega a una base de datos con todas las canciones.
        La base de datos es un arreglo o lista.

        • Crear arbol: Recibe un arreglo o lista de canciones y genera un árbol binario. Cree un árbol
        desde un arreglo/lista ordenado usando búsqueda binaria (lo que resulta en un árbol balanceado) y cree
        otro árbol desde un arreglo sin ordenar.

        • Buscar cancion (nombre): Recibe el nombre de una canción y devuelve el ID de la canción, sino
        existe retorna -1. Busque en los dos árboles creados anteriormente.

        • Buscar cancion (duracion): Recibe una duración en milisegundos y devuelve el ID de las can-
        ciones que tienen esa duración como un arreglo o lista. En caso de no haber ninguna canción con esa
        duración, devuelve un arreglo o lista vacío. Busque en los dos árboles creados anteriormente.

        • Ordenar por nombre: Toma una base de datos de canciones (un arreglo o lista) y devuelve la
        misma estructura en orden lexicográfico.

        • Ordenar por duracion: Toma una base de datos de canciones (un arreglo o lista) y devuelve la
        misma estructura en orden lexicográfico.

    Los métodos de ordenamiento deben ser implementados usando 4 formas: MergeSort, QuickSort, InsertionSort
    y BubbleSort. Tanto para el orden por nombre como por duración, genere una tabla midiendo el tiempo de
    ejecución de cada método y comente los resultados.
*/
