// Lab no evaluado

/*
Calcular digito verificador del rut
1.- Al rut entregado se reordenan los numeros de derecha a izquierda
2.- Estos numeros se multiplican por la serie [2, 3, 4, 5, 6, 7] (si se acaban vuelve a empezar) y se suman todos
3.- Se hace una division entera por 11 y se vuelve a multiplicar por 11
4.- Al resultado del paso 2 se le resta el resultado del paso 3
5.- Finalmente a 11 se le resta el resultado del paso anterior
Recordar: 11 >= 0 y 10 >= K
*/

import java.util.Scanner;

public class Lab_03_21_2024
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el rut sin digito verificador: ");
        int rut = scanner.nextInt();
        digito(rut);
        scanner.close();
    }
    public static void digito(int rut)
    {
        int[] serie = {2, 3, 4, 5, 6, 7};
        int suma = 0;
        int i = 0;
        while (rut > 0)
        {
            int digito = rut % 10;
            suma += digito * serie[i];
            rut /= 10;
            i = (i + 1) % 6;
        }
        int resto = suma % 11;
        int dv = 11 - resto;
        System.out.println("El digito verificador es: " + dv);
    }
}

/*
Matriz transpuesta
- Una matriz transpuesta es aquella que intercambia sus filas por sus columnas
- Escriba un programa que aplique este principio a una matriz nvm
*/

