#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = pair<ll, ll>;
ll dist(st x, st y) {
    auto [a, b] = x;
    auto [c, d] = y;
    return abs(a - c) + abs(b - d);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, a, b; cin >> n >> k >> a >> b; a--, b--;
        vector<st> v(n); for (auto &[x, y] : v) cin >> x >> y;
        st start = v[a], end = v[b];
        ll sbest, ebest;
        sbest = ebest = dist(start, end);
        for (int i = 0; i < k; i++) {
            sbest = min(sbest, dist(start, v[i]));
            ebest = min(ebest, dist(end, v[i]));
        }

        cout << min(dist(start, end), sbest + ebest) << endl;
    }
    return 0;
}
