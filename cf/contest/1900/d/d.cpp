#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        map<int, int> f;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> toadd;
            int cur = f[1];
            ll term = 0;
            for (int d = 1; d * d <= v[i]; d++) {
                if (!(v[i] % d)) {
                    toadd.push_back(d);
                    if (f[d] < cur) {
                        term += (cur - f[d]) * cur;
                        cur = f[d];
                    }
                }
            }
            for (int i : toadd) f[i]++;
            cnt += term * (n - (i + 1));
        }

        cout << cnt << endl;
    }

    return 0;
}
