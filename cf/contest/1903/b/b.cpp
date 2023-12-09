#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        using vi = vector<int>;
        vector<vi> v(n, vi(n)); for (auto &i : v) for (auto &j : i) cin >> j;
        vi a(n, 1);
        for (int i = 0; i < n; i++) {
            int e = v[i][(i + 1) % n];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                e &= v[i][j];
            }
            a[i] = e;
        }
        bool f = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                f &= v[i][j] == (a[i] | a[j]);
            }
        }

        /*
        cout << "\tDEBUG" << endl;
        cout << "\ta"; for (auto i : a) cout << i << " "; cout << endl;
        for (int i = 0; i < n; i++) {
            cout << "\t";
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    cout << "0" << " ";
                    continue;
                }
                cout << (a[i] | a[j]) << " ";
            }
            cout << endl;
        }
        */

        if (f) {
            cout << "YES" << endl;
            for (auto i : a) cout << i << " "; cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
