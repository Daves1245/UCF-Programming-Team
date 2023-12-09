#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;

        set<ll> s;
        for (ll &e : v) {
            while ((e % 10) && ((e % 10) != 2)) {
                e += e % 10;
            }

            if (!(e % 10)) s.insert(e);
        }

        int f = (s.size() == 0) || (s.size() == n);
        int a = 0, b = 0;
        for (ll i : v) {
            a |= (i % 20) == 2;
            b |= (i % 20) == 12;
        }

        f &= !(a && b);

        cout << (f ? "Yes" : "No") << endl;
    }

    return 0;
}
