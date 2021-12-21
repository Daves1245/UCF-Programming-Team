#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        scanf("%d %d %d %d\n", &n, &m, &a, &b);
        int grid[n][m];
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = getchar();
                if (grid[i][j] == '.') count++;
            }
            getchar();
        }

        if (2 * a <= b) {
            cout << count * a << endl;
            continue;
        }

        int cost = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    if (j < m - 1 && grid[i][j + 1] == '.') {
                        cost += b;
                        j++;
                    } else {
                        cost += a;
                    }
                }
            }
        }
        cout << cost << endl;
    }
    return 0;
}

