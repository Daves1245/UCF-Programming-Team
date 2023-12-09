#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (int &i : v) cin >> i;
        int a = 0, b = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == v[i + 1]) continue;
            if (v[i] > v[i + 1]) {
                a = max({a, (v[i] + v[i + 1] + 1) / 2});
            } else {
                b = min({b, (v[i] + v[i + 1]) / 2});
            }
        }

        cout << (a <= b ? a : -1) << endl;
    }

    return 0;
}
