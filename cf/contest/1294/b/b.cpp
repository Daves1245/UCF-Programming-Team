#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n); for (auto &[a, b] : v) cin >> a >> b;
        v.insert(v.begin(), 1, {0, 0});

        sort(v.begin(), v.end());

        string ans = "";
        bool good = true;
        for (int i = 0; i < n; i++) {
            auto [a, b] = v[i];
            auto [c, d] = v[i + 1];
            if (c >= a) for (int j = 0; j < c - a; j++) ans += "R";
            else good = false;
            if (d >= b) for (int j = 0; j < d - b; j++) ans += "U";
            else good = false;
        }

        if (good) {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}
