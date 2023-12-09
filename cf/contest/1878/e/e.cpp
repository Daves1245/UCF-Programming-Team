#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
vll a;
struct node {
    ll l, m, r, v = 0;
    node *left = 0, *right = 0;
    node(int l, int r): l(l), r(r), m((l + r) >> 1) {}
    void check() {
        if (left) return;
        left = new node(l, m);
        right = new node(m + 1, r);
    }
    void update(int i) {
        if (l == r) return void(v = a[i]);
        check();
        if (i <= m) left->update(i);
        else right->update(i);
        v = (left->v) & (right->v);
    }
    int query(int i, int k) {
        // cout << l << " " << r << " " << v << endl;
        if (i < l) return -1;
        if (v >= k) return r + 1;
        if (l == r) return -1;
        check();
        return max(left->query(i, k), right->query(i, k));
    }
};
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        a.resize(n);
        for (ll &i : a) cin >> i;
        vector<vll> bps(32, vll(n + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                bps[j][i + 1] = bps[j][i] + ((a[i] & (1 << j)) > 0);
            }
        }
        auto get = [&](int i, int j) -> ll {
            ll ret = 0;
            for (int k = 0; k < 32; k++) {
                if (bps[k][j] - bps[k][i - 1] >= j - i + 1) ret |= (1 << k);
            }
            return ret;
        };
        auto bs = [&](int l, int m, int k) -> bool {
            return get(l, m) >= k;
        };
        int q; cin >> q;
        while (q--) {
            int l, k; cin >> l >> k;
            int lo = 0, hi = n;
            int m = (lo + hi) >> 1;
            int ans = -1;
            for (int i = 0; i < 64; i++) {
                m = (lo + hi) >> 1;
                if (bs(l, m, k)) {
                    ans = m + 1;
                    lo = m;
                } else {
                    hi = m;
                }
            }
            cout << (ans == -1 ? -1 : ans) << " ";
        }
        cout << endl;
    }
    return 0;
}
