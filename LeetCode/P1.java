/*
    * Problem: 1. Two Sum
    * Source: https://leetcode.com/problems/two-sum/

    Con tablas de hash: O(n)

    1.- Crear una tabla hash para almacenar los números y sus índices.
    2.- Iterar a través del arreglo de números.
    3.- Para cada número, verificar si la tabla hash contiene la diferencia entre el objetivo y el número actual.
    4.- Si la diferencia está en la tabla hash, se ha encontrado dos números que suman al objetivo. Se devuelve los índices de estos dos números.
    5.- Si la diferencia no está en la tabla hash, Se agrega el número actual y su índice a la tabla hash.
    6-. Si se llega al final del arreglo sin encontrar dos números que sumen al objetivo, devuelve un arreglo vacío o lanza una excepción, dependiendo de los requisitos del problema.
*/

import java.util.HashMap;
import java.util.Map;

public class P1
{
    public static void main(String[] args)
    {
        int arr[] = {1, 4, 5, 8, 10, 20};
        int[] result = twoSum(arr, 0);
        System.out.println("Solution: " + result[0] + ", " + result[1]);
    }

    public static int[] twoSum(int[] nums, int target)
    {
    Map<Integer, Integer> indices = new HashMap<>();
    for (int i = 0; i < nums.length; i++)
    {
        int complement = target - nums[i];
        if (indices.containsKey(complement))
        {
            return new int[] {indices.get(complement), i };
        }
        indices.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
}