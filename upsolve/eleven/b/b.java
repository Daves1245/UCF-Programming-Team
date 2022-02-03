import java.io.*;
import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        ArrayList<String> classes = new ArrayList<String>();

        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String name = in.next();
            name = name.substring(0, name.length() - 1);
            String instruction = in.nextLine();
            Scanner tmp = new Scanner(instruction);
            int placement = 0;

            String entry = ""; // builder
            boolean first = true;
            while (tmp.hasNext()) {
                String next = tmp.next();
                if (next.equals("lower")) {
                    entry += "c";
                    first = false;
                }
                if (next.equals("middle") && !first) {
                    entry += "b";
                }
                if (next.equals("upper")) {
                    entry += "a";
                    first = false;
                }
            }

            if (!first) entry += "b";
            entry = new StringBuilder(entry).reverse().toString();
            entry += "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb:" + name;
            classes.add(entry);
        }

        Collections.sort(classes);
        for (String s : classes) {
            /*
               System.out.println(s);
               */
            System.out.println(s.substring(s.indexOf(":") + 1));
        }
    }
}
