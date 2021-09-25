// Danny Wasserman
// 7/23/2014
// Solution to UCF Locals Problem: Chain Email

import java.util.*;
import java.io.*;

public class email {

  public static void main(String[] args) throws Exception {

    // Open file.
    Scanner in = new Scanner(System.in);

    // Read header.
    int n = in.nextInt();
    int s = in.nextInt() - 1;
    boolean[][] g = new boolean[n][n];

    // Read names.
    String[] names = new String[n];
    for (int i = 0; i < n; i++)
      names[i] = in.next();

    // Read in graph.
    for (int i = 0; i < n; i++) {
      int m = in.nextInt();
      for (int j = 0; j < m; j++) {
        int o = in.nextInt() - 1;
        g[i][o] = true;
      }
    }

    // Run Floyd-Warshall's.
    for (int p = 0; p < n; p++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          g[i][j] |= g[i][p] && g[p][j];

   // Check for part of cycle.
    boolean[] inCycle = new boolean[n];
    for (int i = 0; i < n; i++)
      if (g[i][i]) inCycle[i] = true;

    // Mark all reachable from start that are in cycles.
    boolean[] infinite = new boolean[n];
    for (int i = 0; i < n; i++)
      if (g[s][i] && inCycle[i]) infinite[i] = true;

    boolean changed = true;

    // Update list interatively.
    while (changed) {
      changed = false;

      // Try all nodes.
      for (int i = 0; i < n; i++) {

        // Build off ones that are receiving emails forever.
        if (infinite[i]) {

        	// See where they can send email, so these also get emails forever.
          for (int j = 0; j < n; j++) {

            // Mark that a change occurred, noting we have to run again.
            if (g[i][j] && !infinite[j]) {
              infinite[j] = true;
              changed = true;
            }
          }
        }
      }
    }

    // Just count.
    int cnt = 0;
    for (boolean b : infinite)
      if (b) cnt++;

    // Safe!
    if (cnt == 0) {
      System.out.println("Safe chain email!");
    }

    // Print who gets emails forever.
    else {
      for (int i = 0; i < n; i++)
        if (infinite[i]) System.out.printf("%s ", names[i]);
      System.out.println();
    }
  }
}
