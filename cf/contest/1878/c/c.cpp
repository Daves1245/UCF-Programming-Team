#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k, x; cin >> n >> k >> x;
        auto sum = [](ll n) -> ll {
            return n * (n + 1) / 2;
        };
        bool f = (sum(k) <= x) && (sum(n) - sum(n - k) >= x);
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
