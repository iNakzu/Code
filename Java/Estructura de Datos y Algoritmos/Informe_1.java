/*
Ejercicio de desarrollo (03/27/2024)
Diseña una solución algorítmica para el siguiente problema y analiza el tiempo de ejecución utilizando notación O(f(n)).

1.1 Pares entre 2 filas
Diseña un programa que, dada una matriz de tamaño m × n, encuentre todos los pares de números pares que están en dos filas diferentes de la matriz.

Input:
- Dos números enteros m y n separados por espacio que representan las dimensiones de la matriz.
- Las siguientes m líneas contienen una secuencia de n números separados por espacios, que representan los elementos de la matriz.
- La siguiente línea contiene dos enteros, r1 y r2, separados por espacio que representan las filas a procesar.

Output:
La salida posee dos filas, la primera contiene los valores de los números pares encontrados en la primera fila analizada de la matriz separados por espacio, la segunda posee también los números pares encontrados de la segunda fila separados por espacio.

Restricciones:
- m y n pueden ser un valor entre 1 y 1000 inclusive.
- Los elementos de la matriz pueden ser un valor entre -10^8 y 10^8.
- Los valores de r1 y r2 pueden ser entre 1 y menor o iguales a m.
*/

import java.util.Scanner;

public class Informe_1
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserte las dimensiones de la matriz n * m en la misma linea: ");

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[][] matriz =  new int[n][m];

        System.out.println("Ingrese " + m + " filas con " + n + " elementos cada uno:");
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matriz[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Ingrese las dos filas a procesar en la misma linea:");

        int r1 = scanner.nextInt();
        int r2 = scanner.nextInt();

        encontrarPares(matriz, r1, r2);

        scanner.close();
    }
    public static void encontrarPares(int[][] matrix, int r1, int r2)
    {
        System.out.println("Pares de numeros pares en las filas " + r1 + " y " + r2 + ":");

        for (int i = 0; i < matrix[r1 - 1].length; i++) // r1 - 1 para obtener la fila correcta en la matriz (ya que los indices empiezan en 0)
        {
            for (int j = 0; j < matrix[r2 - 1].length; j++)
            {
                if (matrix[r1 - 1][i] % 2 == 0 && matrix[r2 - 1][j] % 2 == 0)
                {
                    System.out.println("(" + matrix[r1 - 1][i] + ", " + matrix[r2 - 1][j] + ")");
                }
            }
        }
    }
}
