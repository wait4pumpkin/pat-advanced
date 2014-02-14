import java.text.NumberFormat;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int sum = a + b;
            System.out.println(NumberFormat.getNumberInstance().format(sum));
        }
    }
}
