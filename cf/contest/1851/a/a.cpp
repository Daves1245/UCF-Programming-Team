#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k, h; cin >> n >> m >> k >> h;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int a = 0; a < n; a++) {
            bool good = false;
            for (int b = 0; b < m; b++) {
                for (int c = 0; c < m; c++) {
                    if (b == c) continue;
                    good |=
                        (h + (b + 1) * k) ==
                        (v[a] + (c + 1) * k)
                        ;
                }
            }
            cnt += good;
        }

        cout << cnt << endl;
    }

    return 0;
}
