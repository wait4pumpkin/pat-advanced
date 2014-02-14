import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.NumberFormat;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

/**
 * Created by pumpkin on 1/28/14.
 */
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int number = Integer.parseInt(reader.readLine());

        List<Integer> nums = new ArrayList<Integer>();
        do {
            nums.clear();
            nums.add(number / 1000);
            number -= nums.get(0) * 1000;
            nums.add(number / 100);
            number -= nums.get(1) * 100;
            nums.add(number / 10);
            number -= nums.get(2) * 10;
            nums.add(number);

            Collections.sort(nums);
            int big = nums.get(3) * 1000 + nums.get(2) * 100 + nums.get(1) * 10 + nums.get(0);
            int small = nums.get(0) * 1000 + nums.get(1) * 100 + nums.get(2) * 10 + nums.get(3);
            number = big - small;
            System.out.println(String.format("%04d", big) + " - " + String.format("%04d", small) + " = " + String.format("%04d", number));
        } while (number != 6174 && number != 0);
    }
}
