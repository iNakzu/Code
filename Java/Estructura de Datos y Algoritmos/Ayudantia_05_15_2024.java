/*
    Ordenar el arreglo {75, 70, 66, 63, 1 ,77 ,78, 27, 56, 8} con los siguientes algoritmos de ordenamiento:
    - Bubble sort
    - Selection sort
    - Insertion sort
    - Merge sort

    Y tener como target el nro. 27 para una busqueda binaria
*/

public class Ayudantia_05_15_2024
{
    public static void main(String[] args)
    {
        int[] array = {75, 70, 66, 63, 1 ,77 ,78, 27, 56, 8};
        selectionSort(array);
        print(array);
    }

    public static void print(int[] arr)
    {
        for (int i : arr)
        {
            System.out.println(i);
        }
    }

    public static void bubbleSort(int[] arr)
    {
        int aux;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (arr[j] > arr[j+1])
                {
                    aux = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                }
            }
        }
    }

    public static void selectionSort(int[] arr)
    {
        for (int i = 0; i < arr.length - 1; ++i)
        {
            int min = i;
            for (int j = i + 1; j < arr.length; ++j)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }

            int aux = arr[min];
            arr[min] = arr[i];
            arr[i] = aux;
        }
    }
}
