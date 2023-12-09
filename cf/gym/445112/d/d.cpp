#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> c(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            if (i == 0) { c[i] = v[i]; continue; }
            c[i] = c[i - 1] + v[i - 1] - v[i];
        }

        ll ans = 0;
        bool z = true;
        for (int i = 0; i < n; i++) {
            while (i < n && s[i] == '0') i++;
            int start = i;
            while (i < n && s[i] == '1') i++;
            int end = i;
            if (end == start) break;
            auto it = max_element(c.begin() + start, c.begin() + end);
            ans += *it;
            i = it - c.begin();
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ans += v[i];
            cout << c[i] << " ";
        }
        cout << endl;
        cout << ans << endl;
    }

    return 0;
}
