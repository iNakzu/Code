/*
Guia 2: Estructuras de datos, tipo de dato abstracto y recursion
*/

import java.util.*;

public class Guia_2
{   
    public static void main(String[] args)
    {

    }
    
    class LinkedList // Definición de una lista enlazada
    {
        class Node
        {
            int value;
            Node next;
    
            Node(int value)
            {
                this.value = value;
            }
        }
    
        Node head;

        /*
        I. Diseñe el método invertir_lista, que recibe el head de una lista para modificarla y dejarla en orden inverso.

        a. Diseñe el método invertir de forma iterativa.
        b. Diseñe el método invertir de forma recursiva.
        */

        public void i(Node head) // Iterative
        {
            Node prev = null;
            Node current = head;
            Node next = null;

            while (current != null)
            {
                next = current.next;
                current.next = prev;
                prev = current;
                current = next;
            }

            head = prev;
        }
    }

    /*
    II. Diseñe un algoritmo que reciba como entrada un arreglo de enteros A y luego lo invierta.

    a. Diseñe un algoritmo que utilice un stack como estructura de datos auxiliar para invertir el arreglo.
    b. Diseñe un algoritmo que invierta el arreglo de forma recursiva, sin utilizar un stack como estructura de datos auxiliar.
    c. Diseñe un algoritmo que invierta el arreglo de forma iterativa, sin usar un stack como estructura
    de datos auxiliar.

    Ejemplo:
    Input:
    A = {1, 2, 3, 6, 7}

    Output:
    A’ = {7, 6, 3, 2, 1}
    */

    public static int[] stack(int[] array)
    {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < array.length; i++)
        {
            stack.push(array[i]);
        }
        for (int i = 0; i < array.length; i++) // 0 1 2 3 4
        {
            array[i] = stack.pop();
        }

        return array;
    }

    public static int[] recursive(int[] array, int[] aux_array, int i)
    {
        if (i == array.length)
        {
            return aux_array;
        }

        aux_array[i] = array[array.length - 1 - i];
        return r(array, aux_array, i + 1);
    }    

    public static int[] iterative(int[] array) // 0 1 2 3 4
    {
        int[] aux_array = new int[array.length];
        int j = 0;
        for (int i = array.length - 1; i >= 0; i--)
        {
            aux_array[j] = array[i];
            j++;
        }
        return aux_array;
    }
}