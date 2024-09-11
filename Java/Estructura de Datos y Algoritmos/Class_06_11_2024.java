/*
    Objetivo: Priority Queue

    - Insert: O(log n)
    - Get Max: O(log n)
*/

import java.util.PriorityQueue;

public class Class_06_11_2024 {
    public static void main(String[] args) {
        // Crear una Priority Queue de enteros
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Agregar elementos a la Priority Queue
        pq.add(5);
        pq.add(3);
        pq.add(7);
        pq.add(1);
        pq.add(9);

        // Obtener y eliminar el elemento más pequeño de la Priority Queue
        int smallest = pq.poll();
        System.out.println("Elemento más pequeño: " + smallest);

        // Obtener el elemento más pequeño sin eliminarlo
        int peek = pq.peek();
        System.out.println("Elemento más pequeño sin eliminarlo: " + peek);

        // Verificar si la Priority Queue está vacía
        boolean isEmpty = pq.isEmpty();
        System.out.println("¿La Priority Queue está vacía? " + isEmpty);
    }
}
