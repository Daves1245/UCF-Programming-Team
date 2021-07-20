import java.util.Scanner;
import java.math.BigInteger;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            BigInteger x = in.nextBigInteger();
            BigInteger y = in.nextBigInteger();

            if (x.subtract(y).compareTo(BigInteger.ONE) > 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
