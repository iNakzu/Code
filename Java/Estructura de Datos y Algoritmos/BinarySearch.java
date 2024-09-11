class BinarySearch
{
    public static void main(String[] args)
    {
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        int target = 5;
        System.out.println(bsi(arr, target));
    }

    static int bsi(int[] arr, int target) // Iterative binary search
    {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    static int bse(int[] arr, int target, int low, int high) // Recursive binary search
    {
        if (high < low)
            return -1;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        // Revisar si target es menor que arr[mid], llamar a la funcion con los nuevos limites
        if (arr[mid] < target)
            return bse(arr, target, mid + 1, high);

        else return bse(arr, target, low, mid - 1);
    }
}