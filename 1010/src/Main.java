/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        String sample = "1 ab 1 2";
        String[] data = sample.split(" ");
        int n = Integer.parseInt(data[2]);
        int radix = Integer.parseInt(data[3]);
        String src = data[n - 1];
        String dst = n <= 1 ? data[1] : data[0];
        int a = 0;

        for (int i = src.length() - 1, k = 0; i >= 0; --i, ++k) {
            int num = parseInt(src.charAt(i));
            a += Math.pow(radix, k) * num;
        }

        int[] nums = new int[dst.length()];
        int maxNum = 0;
        for (int i = dst.length() - 1; i >= 0; --i) {
            nums[i] = parseInt(dst.charAt(i));
            if (nums[i] > maxNum) maxNum = nums[i];
        }

        int result = -1;
        for (int base = maxNum + 1; base < 36; ++base) {
            int b = 0;
            for (int i = dst.length() - 1, k = 0; i >= 0; --i, ++k) {
                b += Math.pow(base, k) * nums[i];
            }
            if (b == a) {
                result = base;
                break;
            }
        }

        if (result > 0) {
            System.out.println(result);
        } else {
            System.out.println("Impossible");
        }
    }

    private static int parseInt(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        } else {
            return c - 'a' + 10;
        }
    }
}
