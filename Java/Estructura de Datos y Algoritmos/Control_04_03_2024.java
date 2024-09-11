 /*
    Cual es el output si el input es n = 5
    Complejidad O(n^4)
*/

public class Control_04_03_2024
{
    public static void main(String[] args) {
        int n = 5;
        int sum = 0;
        for (int i = 1; i <= n * n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                sum++;
            }
        }
        System.out.println(sum);
    }
}
