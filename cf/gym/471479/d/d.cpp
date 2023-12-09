#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v(n); for (auto &i : v) cin >> i;
        auto find_inversions = [&]() -> ll {
            ll ret = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += v[i];
                if (!v[i]) ret += cnt;
            }
            return ret;
        };

        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if ((x < 0) && v[n - 1 - i]) x = n - 1 - i;
            if ((y < 0) && !v[i]) y = i;
        }
        ll ret = find_inversions();
        if (x >= 0) {
            v[x] = !v[x];
            ret = max(ret, find_inversions());
            v[x] = !v[x];
        }
        if (y >= 0) {
            v[y] = !v[y];
            ret = max(ret, find_inversions());
            v[y] = !v[y];
        }

        cout << ret << endl;
    }
    return 0;
}
