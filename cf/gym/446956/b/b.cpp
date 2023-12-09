#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a = {
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {1, 0, 0, 1},
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i % a.size()][j % a.size()] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
