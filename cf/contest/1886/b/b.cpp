#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using dd = pair<ld, ld>;
ld dist(dd p, dd p2) {
    auto [a, b] = p;
    auto [c, d] = p2;
    return sqrtl((a - c) * (a - c) + (b - d) * (b - d));
}
int main() {
    int t; cin >> t;
    while (t--) {
        vector<dd> v(3); for (auto &[x, y] : v) cin >> x >> y;
        dd h = v[0], a = v[1], b = v[2], o = {0, 0};
        cout << fixed << setprecision(10) << min({
                max(dist(a, h), dist(a, o)),
                max(dist(b, h), dist(b, o)),
                max({dist(b, o), dist(a, h), dist(a, b) / 2}),
                max({dist(b, h), dist(a, o), dist(a, b) / 2})
                }) << endl;
    }
    return 0;
}
