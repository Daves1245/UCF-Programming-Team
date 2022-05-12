#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll score(vector<vector<int>> v, int x, int y) {
    int n = v.size(), m = v[0].size();
    int ret = v[x][y];
    int dr[] = {1, -1, -1, 1};
    int dc[] = {1, -1, 1, -1};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int a = x + dr[j] * i;
            int b = y + dc[j] * i;
            if (a >= 0 && a < n && b >= 0 && b < m) ret += v[a][b];
        }
    }
    return ret;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        ll ma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ma = max(ma, score(v, i, j));
            }
        }

        cout << ma << endl;
    }
    return 0;
}
