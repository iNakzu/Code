import java.util.Scanner;

public class Input {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Cuanto mide el cateto a?");
        double a = scanner.nextDouble();
        System.out.println("Cuanto mide el cateto b?");
        double b = scanner.nextDouble();

        double c = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));

        System.out.print("La hipotenusa mide: " + c + "\n");

        scanner.close();
    }
}
