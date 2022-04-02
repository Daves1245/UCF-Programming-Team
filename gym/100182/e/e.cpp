#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    while (scanf("%d %d\n", &r, &c) && r != 0 && c != 0) {
        vector<vector<int>> grid(r + 2, vector<int>(c + 2, 0));
        
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                grid[i][j] = getchar();
            }
            getchar();
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] == '.') {
                    grid[i][j] = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (grid[i + x][j + y] == '*')
                                grid[i][j]++;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j] == '*') cout << (char)grid[i][j];
                else cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

