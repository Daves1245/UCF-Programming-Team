#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                l = i; break;
            }
        }
        for (int i = n - 1; i; i--) {
            if (v[i] > 0) {
                r = i;
                break;
            }
        }

        if (l == -1) {
            cout << 0 << endl;
            continue;
        }

        if (l == r) {
            cout << 1 << endl;
            continue;
        }

        bool good = true;
        for (int i = l; i < r; i++) {
            if (v[i] == 0) {
                good = false;
                continue;
            }
        }

        cout << (good ? 1 : 2) << endl;
    }

    return 0;
}
