/*
 * Author: Zedbar
 * Date: 2021-06-21
 */

import java.util.Scanner;
import java.math.BigInteger;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int b, n;
        BigInteger a = BigInteger.valueOf(in.nextInt());
        b = in.nextInt();
        n = in.nextInt();

loop: for (int i = 0; i < n; i++) {
          BigInteger tmp = a;
          for (BigInteger j = a.multiply(BigInteger.TEN); j.compareTo(tmp.add(BigInteger.ONE).multiply(BigInteger.TEN)) > 0; j = j.add(BigInteger.ONE)) {
              System.out.println(a.multiply(BigInteger.TEN) + ", " + tmp.add(BigInteger.ONE).multiply(BigInteger.TEN));
              if (j.remainder(BigInteger.valueOf(b)).compareTo(BigInteger.ZERO) == 0) {
                  a = j;
                  continue loop;
              }
              System.out.println(-1);
              return;
          }
}
System.out.println(a);
    }
}
