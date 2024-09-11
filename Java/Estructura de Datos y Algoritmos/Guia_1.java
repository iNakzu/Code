public class Guia_1 {
    public static void main(String[] args)
    {
    }

    /*
    1.- Invertir un entero
    Dado un numero entero n, disenhe un algoritmo que invierta sus digitos.

    Input: n = 2674
    Output: 4762
    */

    public static int i(int n) {
        int reversed = 0;
        while (n != 0) {
            int digit = n % 10;
            n /= 10;
            reversed = reversed * 10 + digit;
        }
        return reversed;
    }

    /*
    2. Arreglo circular
    Dado un arreglo A de numeros enteros, con tamano n. Disene un algoritmo que rota el arreglo a la
    izquierda r posiciones.

    Input:
    n = 4
    A = {5, 7, 8, 9}
    r = 1
    Output: {7, 8, 9, 5}
    */

    public static void ii(int[] array, int d) // {0,1,2,3,4} -> {1,2,3,4,0}
    {
        for (int i = 0; i < d; i++) // Cantidad de desplazamientos
        {
            int temp = array[0];
            for (int j = 0; j < array.length - 1; j++)
            {
                array[j] = array[j + 1];
            }
            array[array.length - 1] = temp;
        }

        for (int i = 0; i < array.length; i++)
        {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    /*
    3. Arreglo incremental
    Dado un arreglo de N enteros, se le pide modificar el arreglo de forma que sea incremental, es decir
    que cada elemento en la secuencia sea igual o mayor que el elemento previo. Para realizar esta
    modificaci ́on en cada movimiento la unica operacion disponible es incrementar el valor de un
    elemento cualquiera en el arreglo en 1. Disene un algoritmo que retorne la cantidad mınima de modificaciones.

    Input:
    N = 5
    A = {2, 4, 3, 5}
    Output: 2
     */

    public static int iii(int[] a)
    {
        int n = a.length;
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                count += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
        }

        return count;
    }

    /*
    4.- Todos los pares de un arreglo
    Sea un arreglo de n enteros disene un algoritmo que retorne una matriz a de n filas y 2 columnas
    dimensiones que contenga cada par posible en el arreglo.

    Input:
    n = 3
    a = {1, 2, 3}
    Output:
    { {1, 1}, {1, 2} {1, 3},
    {2, 1}, {2, 2}, {2, 3},
    {3, 1}, {3, 2}, {3, 3} }
    */

    public static int[][] iv(int[] a)
    {
        int n = a.length;
        int[][] pairs = new int[n * n][2];
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pairs[index][0] = a[i];
                pairs[index][1] = a[j];
                index++;
            }
        }

        return pairs;
    }


    /*
    5.- Multiplicacion de matrices
    Sean dos matrices m_1 y m_2, ambas matrices de n filas y N columnas. Disene un algoritmo que reciba
    dos matrices de enteros como entrada y retorne la matriz resultante al multiplicar ambas matrices.

    Input:
    n = 2
    m_1 = {{2, 2}, {3, 3}}
    m_2 = {{5, 5}, {10, 10}}
    Output: {{30, 30}, {45, 45}}
    2
    */

    public static int[][] v(int[][] m1, int[][] m2)
    {
        int n = m1.length;
        int[][] result = new int[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        return result;
    }

}