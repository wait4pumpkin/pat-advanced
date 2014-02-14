import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        try {
            String sample = "10\n" +
                            "-10 1 2 3 4 -5 -23 3 7 -21";
            BufferedReader reader = new BufferedReader(new StringReader(sample));
            int size = Integer.parseInt(reader.readLine());
            int[] data = new int[size];
            boolean allNegative = true;
            Scanner scanner = new Scanner(reader.readLine());
            for (int i = 0; i < size; ++i) {
                data[i] = scanner.nextInt();
                if (data[i] > 0) allNegative = false;
            }

            if (allNegative) {
                System.out.println(0 + " " + data[0] + " " + data[size - 1]);
                return;
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
