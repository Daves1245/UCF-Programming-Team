#include <bits/stdc++.h>

using namespace std;

int dr[] = {1, -1, -1, 1};
int dc[] = {1, -1, 1, -1};

long long score(vector<vector<int>> v, int x, int y) {
    int ret = v[x][y];
    int n = v.size(), m = v[0].size();
    for (int i = 1; i <= n; i++) {
        int a, b;
        a = x + i, b = y + i;
        if (a >= 0 && a < n && b >= 0 && b < m) {
            ret += v[a][b];
        }
        a = x - i, b = y - i;
        if (a >= 0 && a < n && b >= 0 && b < m) {
            ret += v[a][b];
        }
        a = x + i, b = y - i;
        if (a >= 0 && a < n && b >= 0 && b < m) {
            ret += v[a][b];
        }
        a = x - i, b = y + i;
        if (a >= 0 && a < n && b >= 0 && b < m) {
            ret += v[a][b];
        }
    }

    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        long long ma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ma = max(ma, score(grid, i, j));
            }
        }

        cout << ma << endl;
    }
    return 0;
}

