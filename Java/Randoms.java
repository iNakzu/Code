import java.util.Random;

public class Randoms {
    public static void main(String[] args)
    {
        Random random = new Random();

        int x = random.nextInt(10) + 1; // Numeros randoms del 0 al 10

        System.out.println(x);
    }
}
