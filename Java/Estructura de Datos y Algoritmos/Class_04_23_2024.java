/*
    Merge Sort
*/

public class Class_04_23_2024 
{
    public static void main(String[] args)
    {
        int[] array = {2, 4, 1, 6, 8, 5, 3, 7, 9, 0};
        mergeSort(array, 0, array.length - 1);

        for (int i : array)
        {
            System.out.println(i);
        }
    }

    public static void merge(int [] a, int lo, int mid, int hi)
    {
        int[] left = new int[mid - lo + 1];
        int[] right = new int[hi - mid];

        for (int i = 0; i < left.length; i++)
        {
            left[i] = a[lo + i];
        }

        for (int j = 0; j < right.length; j++)
        {
            right[j] = a[mid + 1 + j];
        }

        int i = 0, j = 0, k = lo;

        while (i < left.length && j < right.length)
        {
            if (left[i] <= right[j])
            {
                a[k] = left[i];
                i++;
            }
            else
            {
                a[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.length)
        {
            a[k] = left[i];
            i++;
            k++;
        }

        while (j < right.length)
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] a, int lo, int hi)
    {
        if (lo < hi)
        {
            int mid = (lo + hi) / 2;
            mergeSort(a, lo, mid);
            mergeSort(a, mid + 1, hi);
            merge(a, lo, mid, hi);
        }
    }
}