#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define lsb(x) __builtin_ctz((x))
int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n), x(q); for (auto &i : a) cin >> i; for (auto &i : x) cin >> i;
        sort(x.begin(), x.end());
        vector<ll> ps(32, 0);
        for (int i = 0; i < q; i++) {
            ps[x[i] - 1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ps.size(); j++) {
                a[i] += !(a[i] % (1 << j)) * ps[j];
            }
        }

        for (auto i : a) cout << i << " "; cout << endl;
    }

    return 0;
}
