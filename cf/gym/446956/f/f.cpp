#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<pair<int, int>> f(m); for (auto &[a, b] : f) cin >> a >> b;

        vector<int> deg(n, 0);
        for (auto [a, b] : f) {
            deg[a - 1]++;
            deg[b - 1]++;
        }

        if (m % 2 == 0) {
            cout << 0 << endl;
        }

        for (int i = 0; i < n; i++) {
            if (deg[i] % 2) {
                cout << << endl;
            }
        }
    }

    return 0;
}
