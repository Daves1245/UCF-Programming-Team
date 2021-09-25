// Arup Guha
// 7/24/2014
// Solution to UCF Locals Problem: Chain Email

import java.util.*;
import java.io.*;

public class email2 {

    public static void main(String[] args) throws Exception {

            Scanner stdin = new Scanner(System.in);

			// Read in names.
            int n = stdin.nextInt();
            int start = stdin.nextInt() - 1;
            String[] names = new String[n];
            for (int i=0; i<n; i++)
                names[i] = stdin.next();

			// Store graph.
            boolean[][] graph = new boolean[n][n];
            for (int i=0; i<n; i++) {
                int e = stdin.nextInt();
                for (int j=0; j<e; j++) {
                    int next = stdin.nextInt() - 1;
                    graph[i][next] = true;
                }
            }

			// Calculate reachability.
            boolean[][] canReach = new boolean[n][n];
            for (int i=0; i<n; i++)
                dfs(graph, i, canReach[i]);

			// Store who gets emails forever.
            boolean[] added = new boolean[n];
            boolean safe = true;

            // Try each node to find all reachable cycles from source.
            for (int i=0; i<n; i++) {

            	// Can't get here.
                if (!canReach[start][i]) continue;

                // See if this node, reachable from start, is part of a cycle.
                for (int j=0; j<n; j++) {
                    if (i == j) continue;
                    if (canReach[i][j] && canReach[j][i]) {
                        added[i] = true;
                        safe = false;
                        break;
                    }
                }
            }

			// Now we tally up all emails forever.
            for (int i=0; i<n; i++) {

            	// No need to check.
                if (added[i]) continue;

                // Can't get here.
                if (!canReach[start][i]) continue;

                // j gets emails forever and can send to i, so i gets them forever also.
                for (int j=0; j<n; j++) {
                    if (i == j) continue;
                    if (canReach[j][i] && added[j]) {
                        added[i] = true;
                        safe = false;
                    }
                }
            }

			// No one gets emails forever!
            if (safe) System.out.println("Safe chain email!");

            // Typical case...
            else {

				// Print out what we need.
                for (int i=0; i<n; i++)
                    if (added[i])
                        System.out.print(names[i]+" ");
                System.out.println();
            }
    }

	// Typical depth first search.
    public static void dfs(boolean[][] gr, int node, boolean[] used) {
        used[node] = true;
        for (int i=0; i<used.length; i++)
            if (!used[i] && gr[node][i])
                dfs(gr, i, used);
    }
}
