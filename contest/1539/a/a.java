import java.util.Scanner;
import java.math.BigInteger;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int n1 = in.nextInt(), x1 = in.nextInt(), t1 = in.nextInt();
            BigInteger n = BigInteger.valueOf(n1);
            BigInteger x = BigInteger.valueOf(x1);
            BigInteger t = BigInteger.valueOf(t1);
            BigInteger tx = t.divide(x);
            BigInteger chunk = tx.multiply(n.subtract(tx));
            BigInteger limit = tx.min(n);
            BigInteger sum = limit.multiply(limit.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2));
            if (x1 > t1) {
                System.out.println(0);
            } else {
                System.out.println(chunk.add(sum));
            }
        }
    }
}
