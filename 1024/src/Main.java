import java.math.BigInteger;
import java.util.Scanner;
/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger number = scanner.nextBigInteger();
        int maxStep = scanner.nextInt();

        int step = 0;
        do {
            if (isPalindromic(number)) break;
            number = number.add(reverseInt(number));
            ++step;
        } while (step < maxStep);
        System.out.println(number);
        System.out.println(step);
    }

    private static BigInteger reverseInt(BigInteger num) {
        return new BigInteger(new StringBuffer(num.toString()).reverse().toString());
    }

    private static boolean isPalindromic(BigInteger num) {
        String data = num.toString();
        for (int i=0, j=data.length()-1; j>i; ++i, --j) {
            if (data.charAt(i) != data.charAt(j)) return false;
        }
        return true;
    }
}
