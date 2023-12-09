#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> v(n); for (auto &i : v) cin >> i;
        v.push_back(v.back() + 2 * (x - v.back()));

        int f = v[0];
        for (int i = 0; i < n; i++) {
            f = max(f, v[i + 1] - v[i]);
        }

        cout << f << endl;
    }

    return 0;
}
