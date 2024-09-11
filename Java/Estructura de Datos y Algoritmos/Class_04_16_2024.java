/*
    Insert Sort
    Bubble Sort
    Selection Sort
*/

public class Class_04_16_2024
{
    public static void main(String[] args)
    { 
        int[] array = {4, 3, 2, 10, 12, 1, 5, 6};
        print(array);
    }

    public static void selectionSort(int arr[]) {
        int n = arr.length;
    
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
                    
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void insertionSort(int arr[])
    {
        for (int i = 1; i < arr.length; ++i)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    public static void print(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
        {
            System.out.println(arr[i]);
        }
    }
}
