#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;

        int mi = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mn > v[i]) {
                mn = v[i];
                mi = i;
            }
        }

        if (is_sorted(v.begin() + mi, v.end())) {
            cout << mi << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
