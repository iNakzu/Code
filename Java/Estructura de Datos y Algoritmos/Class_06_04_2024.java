/*
    Hash Table
*/

import java.util.HashMap;
import java.util.Collection;
import java.util.Set;

public class Class_06_04_2024 {
    public static void main(String[] args) {
        // Crear una instancia de Hash Table
        HashMap<String, Integer> hashTable = new HashMap<>();

        // Agregar elementos a la Hash Table
        hashTable.put("Juan", 25);
        hashTable.put("María", 30);
        hashTable.put("Pedro", 35);

        // Obtener el valor asociado a una clave
        int edad = hashTable.get("María");
        System.out.println("La edad de María es: " + edad);

        // Verificar si una clave existe en la Hash Table
        boolean existe_pedro = hashTable.containsKey("Pedro");
        System.out.println("¿Pedro existe en la Hash Table? " + existe_pedro);

        // Eliminar un elemento de la Hash Table
        hashTable.remove("Juan");

        // Obtener el tamaño de la Hash Table
        int tamaño = hashTable.size();
        System.out.println("El tamaño de la Hash Table es: " + tamaño);
        // Agregar un nuevo elemento a la Hash Table
        hashTable.put("Luis", 40);

        // Actualizar el valor asociado a una clave existente
        hashTable.put("María", 31);

        // Obtener todas las claves de la Hash Table
        Set<String> claves = hashTable.keySet();
        System.out.println("Las claves de la Hash Table son: " + claves);

        // Obtener todos los valores de la Hash Table
        Collection<Integer> valores = hashTable.values();
        System.out.println("Los valores de la Hash Table son: " + valores);

        // Verificar si un valor existe en la Hash Table
        boolean existeValor = hashTable.containsValue(35);
        System.out.println("¿Existe el valor 35 en la Hash Table? " + existeValor);

        // Vaciar la Hash Table
        hashTable.clear();

        // Verificar si la Hash Table está vacía
        boolean estaVacia = hashTable.isEmpty();
        System.out.println("¿La Hash Table está vacía? " + estaVacia);
    }
}
