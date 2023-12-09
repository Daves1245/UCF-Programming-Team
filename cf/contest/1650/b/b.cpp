#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll l, r, a; cin >> l >> r >> a;
        ll b = r - (r % a) - 1;
        auto f = [&](int x) -> ll { return (x / a) + (x % a); };
        if (b >= l) cout << max(f(b), f(r)) << endl;
        else cout << f(r) << endl;
    }
    return 0;
}
