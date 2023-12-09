#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for (auto &[a, b] : v) cin >> a >> b;
        bool f = 0;
        for (int i = 1; i < n; i++) {
            auto [a, b] = v[i];
            f |= (a >= v[0].first) && (b >= v[0].second);
        }
        cout << (!f ? v[0].first : -1) << endl;
    }
    return 0;
}
