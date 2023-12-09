#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0;
        vector<int> f;
        int seen;
        for (int i = 0; i < n; i++) {
            bool g = 1;
            f.assign(10, 0);
            seen = 0;
            int mx = 0;
            for (int j = 0; j < 100; j++) {
                if (i + j >= n) break;
                int c = s[i + j] - '0';
                seen |= (1 << c);
                f[c]++;
                mx = max(mx, f[c]);
                cnt += g = mx <= __builtin_popcount(seen);

                // cout << i << " " << j << " " << s.substr(i, j + 1) << " " << f[c] << " " << __builtin_popcount(seen) << " " << cnt << " " << g << endl;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
