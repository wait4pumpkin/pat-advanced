import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int nCase = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= nCase; ++i) {
            Scanner scanner = new Scanner(reader.readLine());
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            BigInteger c = scanner.nextBigInteger();
            System.out.println("Case #" + i + ": " + ((a.add(b).compareTo(c) > 0) ? "true" : "false" ));
        }
    }
}
