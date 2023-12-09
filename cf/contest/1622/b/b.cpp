#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        using st = tuple<int, int, int, int>;
        vector<st> v(n);
        for (int i = 0; i < n; i++) {
            auto &[val, id, b, ans] = v[i];
            cin >> val;
            id = i;
        }
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            auto &[val, id, b, ans] = v[i];
            b = s[i] == '1';
        }

        sort(v.begin(), v.end());
        int k = 0;
        for (auto &[val, id, b, ans] : v) {
            if (!b) ans = ++k;
        }
        for (auto &[val, id, b, ans] : v) {
            if (b) ans = ++k;
        }

        sort(v.begin(), v.end(), [](const st &a, const st &b) -> bool {
                auto [c, d, e, f] = a;
                auto [g, h, i, j] = b;
                return d < h;
                });

        for (auto &[val, id, b, ans] : v) {
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
