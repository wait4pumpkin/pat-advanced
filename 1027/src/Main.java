import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.Scanner;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            Scanner scanner = new Scanner(reader.readLine());
            int[] nums = new int[3];
            for (int i = 0; i < 3; ++i) {
                nums[i] = scanner.nextInt();
            }

            System.out.print("#" + Main.intToStr(nums[0], 13) + Main.intToStr(nums[1], 13) + Main.intToStr(nums[2], 13));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String intToStr(int i, int radix) {
        String result = Character.toString(Main.intToChar(i / radix));
        result += Character.toString(Main.intToChar(i % radix));
        return result;
    }

    private static char intToChar(int i) {
        if (i >= 0 && i <= 9) {
            return (char)(i + '0');
        } else {
            return (char)(i + 'A' - 10);
        }
    }
}
