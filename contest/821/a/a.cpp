#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &i : v) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    bool bad = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != 1) {
                bool good = false;
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (v[k][j] + v[i][l] == v[i][j]) {
                            good = true;
                        }
                    }
                }

                if (!good) {
                    bad = true;
                }
            }
        }
    }

    cout << (!bad ? "Yes" : "No") << endl;
    return 0;
}

