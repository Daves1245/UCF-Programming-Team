#include <bits/stdc++.h>
using namespace std;
#define mod(a, b) ((a + n) % b)
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, r, c; cin >> n >> k >> r >> c;
        vector<vector<char>> g(n, vector<char>(n, '.'));
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                auto draw = [&](int a, int b) -> void {
                    for (int i = 0; i < k; i++) {
                        int x = mod(a + i, n), y = mod(b + i, n);
                        g[x][y] = 'X';
                    }
                };
                draw(i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = mod(i - r, n), y = mod(j - c, n);
                cout << g[x][y];
            }
            cout << endl;
        }
    }
    return 0;
}
