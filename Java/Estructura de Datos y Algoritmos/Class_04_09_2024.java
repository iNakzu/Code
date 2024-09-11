import java.util.*;

public class Class_04_09_2024 {
    public static void main(String[] args)
    {
    }
    
    public static int factorial(int n) // O(n)
    {
        if (n == 0) {
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    public static int fibonacci(int n) // O(2^n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    public static int[] invertArray(int[] array) // Con stack
    {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < array.length; i++)
        {
            stack.push(array[i]);
        }
        for (int i = 0; i < array.length; i++)
        {
            array[i] = stack.pop();
        }
        return array;
    }
    
    public static void hanoi(int n, char from, char to, char aux) {
        if (n == 0) {
            return;
        }
        if (n == 1) {
            System.out.println("Move disk 1 from rod " + from + " to rod " + to);
            return;
        }
        hanoi(n - 1, from, aux, to);
        System.out.println("Move disk " + n + " from rod " + from + " to rod " + to);
        hanoi(n - 1, aux, to, from);
    }
}
