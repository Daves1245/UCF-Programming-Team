#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        vector<vector<int>> g(10, vector<int>(10));
        vector<string> v(10); for (auto &i : v) cin >> i;
        for (auto &i : g) for (auto &j : i) j = 1;
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                g[i][j] = 2;
            }
        }
        for (int i = 2; i < 8; i++) {
            for (int j = 2; j < 8; j++) {
                g[i][j] = 3;
            }
        }
        for (int i = 3; i < 7; i++) {
            for (int j = 3; j < 7; j++) {
                g[i][j] = 4;
            }
        }
        for (int i = 4; i < 6; i++) {
            for (int j = 4; j < 6; j++) {
                g[i][j] = 5;
            }
        }
        int score = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (v[i][j] == 'X') {
                    score += g[i][j];
                }
            }
        }

        cout << score << endl;
    }
    return 0;
}
