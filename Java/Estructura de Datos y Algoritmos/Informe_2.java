/*
    Una persona que usted quiere mucho ya no puede pagar más un reproductor de música premium, usted (05/16/2024)
    y sus grandes habilidades tecnológicas decide poner su mente y corazón en armarle su propio reproductor de
    música usando las estructuras lineales aprendidas en su ramo favorito "Estructura de Datos y Algoritmos".
    Se debe diseñar e implementar un sistema de reproducción de música utilizando el lenguaje de programación
    Java. El sistema debe ser capaz de realizar las siguientes operaciones:
    
    1. Agregar canción: Permite al usuario agregar una nueva canción al sistema, incluyendo su título, artista
    y duración. Las canciones agregadas se colocarán en la cola de reproducción.
    
    2. Eliminar canción: Permite al usuario eliminar una canción del sistema utilizando su nombre y artista.
    La canción se eliminará de la cola de reproducción.
    
    3. Historial de reproducción: Mantiene un registro de las canciones reproducidas por el usuario en orden
    cronológico inverso, utilizando un stack para el historial.
    
    4. Reproducir: Permite al usuario reproducir la siguiente canción de la cola de reproducción en el orden en
    que fueron agregadas (elimina la actual de la cola de reproducción y avanza al siguiente).
    
    5. Biblioteca de reproducción: Permite al usuario generar nuevas colas de reproducción y gestionarlas.
    La biblioteca se manejará como una Lista de Colas, donde cada elemento de la lista representa una cola
    de reproducción independiente.
    
    Para implementar este sistema, debe cumplir con las siguientes características:
    - Debe existir un main con el cual se puedan utilizar todas las funciones y probar su utilidad.
    - Utilizar clases y objetos para representar canciones, el historial de reproducción y las colas de reproducción.
    - Utilizar la clase LinkedList para implementar la Biblioteca, la cual es una Lista de Colas de reproducción.

    Además de estas operaciones básicas, puedes considerar agregar las siguientes opciones para enriquecer la funcionalidad del sistema:

    1. Buscar canción: Permite al usuario buscar una canción por su título o artista en la cola de reproducción o en el historial (muestra lo encontrado).

    2. Crear cola de reproducción personalizada: Permite al usuario crear colas de reproducción personalizadas agrupando canciones según sus preferencias (Relacionado con Biblioteca de Reproducción).

    3. Reproducir playlist: Elimina la actual cola de reproducción y pone la playlist seleccionada de la biblioteca de Reproducción.

    4. Estadísticas de reproducción: Muestra al usuario estadísticas sobre las canciones más reproducidas, duración total de reproducción usando como medida la unidad mas grande posible a representar (segundos, minutos, horas, etc). Utilizando la información de las colas de reproducción y el historial.

    5. Mostrar siguientes: Enseña las siguientes 10 canciones a reproducir.

    6. Mostrar historial de reproducción: Enseña las últimas 10 canciones (si es que existen) presentes en el historial.
*/

import java.util.Stack;

public class Informe_2
{
    public static void main(String[] args)
    {
        Reproductor reproductor = new Reproductor();
        
        Cancion s1 = new Cancion("Time Flies", "Drake", 180);
        Cancion s2 = new Cancion("Cancion 2", "Artista 2", 60);
        Cancion s3 = new Cancion("Cancion 3", "Artista 3", 210);
    }

    public static class Cancion
    {
        private String titulo, artista;
        private int duracion;
        private Cancion next;

        Cancion(String titulo, String artista, int duracion)
        {
            this.titulo = titulo;
            this.artista = artista;
            this.duracion = duracion;
            this.next = null;
        }        
    }

    public static class Reproductor
    {
        private Cancion head;
        private Stack<Cancion> historial;
        
        public Reproductor()
        {
            historial = new Stack<>();
        }
        public void agregarCancion(Cancion song)
        {
            if (head == null)
            {
                head = song;
            }
            else
            {
                Cancion current = head;
                while (current.next != null)
                {
                    current = current.next;
                }
                current.next = song;
            }
        }

        public void eliminar_cancion(String nombre, String artista)
        {
            if (head == null)
            {
                System.out.println("La lista de reproduccion esta vacia");
                return;
            }

            if (head.titulo == nombre && head.artista == artista)
            {
                head = head.next;
                System.out.println("La cancion " + nombre + " de " + artista + " se ha eliminado");
                return;
            }

            Cancion current = head;
            while (current.next != null)
            {
                if (current.next.titulo == nombre && current.next.artista == artista)
                {
                    current.next = current.next.next;
                    System.out.println("La cancion " + nombre + " de " + artista + " se ha eliminado");
                    return;
                }
                current = current.next;
            }

            System.out.println("La cancion " + nombre + " de " + artista + " no se encuentra en la lista de reproduccion");
        }

        public void reproducir()
        {
            if (head != null)
            {
                System.out.println("Reproduciendo " + head.titulo + " de " + head.artista);
                historial.push(head);
                head = head.next;
            }
            else
            {
                System.out.println("La lista de reproduccion esta vacia");
            }
        }

        public void buscarCancion(String nombre, String artista)
        {
            Cancion current = head;
            while (current != null)
            {
                if (current.titulo == nombre || current.artista == artista)
                {
                    System.out.println("Cancion encontrada: " + current.titulo + " de " + current.artista);
                }
                current = current.next;
            }
        }

        public void mostrarSiguientes()
        {
            System.out.println("Lista de reproduccion:");
            Cancion current = head;
            int count = 1;
            while (current != null && count <= 10)
            {
                System.out.println("Titulo: " + current.titulo + ", Artista: " + current.artista + ", Duracion: " + current.duracion);
                current = current.next;
                count++;
            }
        }

        public void mostrarHistorial()
        {
            System.out.println("Historial de reproduccion:");
            int counter = 0;
            for (Cancion song : historial)
            {
                if (counter == 10) {
                    break;
                }
                System.out.println("Titulo: " + song.titulo + ", Artista: " + song.artista + ", Duracion: " + song.duracion);
                counter++;
            }
        }
    }
}
