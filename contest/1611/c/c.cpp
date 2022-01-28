/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int f = v[0], l = v[v.size() - 1];
        bool a = true, b = true;
        for (int i = 0; i < n; i++) {
            if (v[i] > f) {
                a = false;
            }
            if (v[i] > l) {
                b = false;
            }
        }

        if (!(a or b)) {
            cout << -1 << endl;
            continue;
        }
        reverse(v.begin(), v.begin() + n / 2);
        reverse(v.begin() + n / 2, v.end());
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

