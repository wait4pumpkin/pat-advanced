import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger number = scanner.nextBigInteger();
        BigInteger target = number.multiply(new BigInteger("2"));
        int[] flags = new int[10];
        while (number.compareTo(new BigInteger("0")) > 0) {
            int pos = Integer.parseInt(number.remainder(new BigInteger("10")).toString());
            ++flags[pos];
            number = number.divide(new BigInteger("10"));
        }

        boolean isTrue = true;
        number = target;
        while (number.compareTo(new BigInteger("0")) > 0) {
            int pos = Integer.parseInt(number.remainder(new BigInteger("10")).toString());
            --flags[pos];
            if (flags[pos] < 0) {
                isTrue = false;
                break;
            }
            number = number.divide(new BigInteger("10"));
        }

        System.out.println(isTrue ? "Yes" : "No");
        System.out.println(target);
        System.out.flush();
    }
}
