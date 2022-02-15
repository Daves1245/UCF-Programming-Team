#include <bits/stdc++.h>

using namespace std;

using grid = vector<vector<char>>;

bool dragon(char c) {
    return c == '^' || c == '>' || c == 'V' || c == '<';
}

void floodfill(grid &g, int i, int j, int dir) {
    if (i < 0 || i >= g.size() || j < 0 || j >= g[i].size()
            || g[i][j] == 'X' || g[i][j] == 'F') return;
    if (!dragon(g[i][j]))
        g[i][j] = 'F';
    switch (dir) {
        case 0:
            // ^
            floodfill(g, i - 1, j - 1, dir);
            floodfill(g, i - 1, j,     dir);
            floodfill(g, i - 1, j + 1, dir);
            break;
        case 1:
            // >
            floodfill(g, i - 1, j + 1, dir);
            floodfill(g, i,     j + 1, dir);
            floodfill(g, i + 1, j + 1, dir);
            break;
        case 2:
            // V
            floodfill(g, i + 1, j - 1, dir);
            floodfill(g, i + 1, j,     dir);
            floodfill(g, i + 1, j + 1, dir);
            break;
        case 3:
            // <
            floodfill(g, i - 1, j - 1, dir);
            floodfill(g, i,     j - 1, dir);
            floodfill(g, i + 1, j - 1, dir);
            break;
    }
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        grid g(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = getchar();
            }
            getchar();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                switch (g[i][j]) {
                    int dir;
                    case '^':
                    dir = 0;
                    // ^
                    floodfill(g, i - 1, j - 1, dir);
                    floodfill(g, i - 1, j,     dir);
                    floodfill(g, i - 1, j + 1, dir);
                    break;
                    case '>':
                    dir = 1;
                    // >
                    floodfill(g, i - 1, j + 1, dir);
                    floodfill(g, i,     j + 1, dir);
                    floodfill(g, i + 1, j + 1, dir);
                    break;
                    case 'V':
                    dir = 2;
                    // V
                    floodfill(g, i + 1, j - 1, dir);
                    floodfill(g, i + 1, j,     dir);
                    floodfill(g, i + 1, j + 1, dir);
                    break;
                    case '<':
                    dir = 3;
                    // <
                    floodfill(g, i - 1, j - 1, dir);
                    floodfill(g, i,     j - 1, dir);
                    floodfill(g, i + 1, j - 1, dir);
                    break;
                }
            }
        }

        cout << "Map #" << t << ":" << endl;
        for (auto i : g) {
            for (auto j : i) {
                cout << j;
            }
            cout << endl;
        }
    }
    return 0;
}

