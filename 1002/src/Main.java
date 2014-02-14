import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double[] a = new double[1001];
        double[] b = new double[1001];
        double[] result = new double[1001];
        while (scanner.hasNext()) {
            for (int line = 0; line < 2; ++line) {
                int length = scanner.nextInt();
                for (int i = 0; i < length; ++i) {
                    int n = scanner.nextInt();
                    if (line <= 0) {
                        a[n] = scanner.nextDouble();
                    } else {
                        b[n] = scanner.nextDouble();
                    }
                }
            }

            int counter = 0;
            for (int i = 0; i < result.length; ++i) {
                result[i] = a[i] + b[i];
                if (result[i] > 0) ++counter;
            }

            System.out.print(counter);
            DecimalFormat formatter = new DecimalFormat("#.0");
            for (int i = result.length - 1; i >= 0; --i) {
                if (result[i] > 0) {
                    System.out.print(" " + i + " " + formatter.format(result[i]));
                }
            }
            System.out.println();
        }
    }
}
