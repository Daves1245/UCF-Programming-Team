/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (n == 1) {
            if (v[0] < 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            continue;
        }

        bool good = v[n - 1] - v[n - 2] < 2;
        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

