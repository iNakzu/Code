/*
    Diseña un algoritmo que recibe como entrada un string que puede estar compuesto por los siguientes
    caracteres: [ ] ( ) { }
    Como output, el algoritmo debe retornar un booleano que describa si la expresión formada es válida,
    es decir, que para cada símbolo de apertura, existe un símbolo de cierre en el lugar correcto.
    
    Ejemplo 1:
    Input:
    { ( ) [ ] }

    Output:
    true
    
    Ejemplo 2:
    Input:
    { } ( ) [ ( ]

    Output:
    false
*/

import java.util.Stack;

public class Control_04_17_2024
{
    public static void main(String[] args)
    {
        System.out.println(isValid("{()[]}"));
    }

    public static boolean isValid(String s)
    {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if (c == '(')
            stack.push(')');
            else if (c == '{')
            stack.push('}');
            else if (c == '[')
            stack.push(']');
            else if (stack.isEmpty() || stack.pop() != c)
            return false;
        }
        return stack.isEmpty();
    }


    public static int f(int n)
    {
        if (n == 0) {
            return 1;
        }
        return f(n - 1) * 2;
    }

    public static int g(int n)
    {
        if (n <= 1) {
            return 0;
        }
        return g(n / 2) + 1;
    }
}

