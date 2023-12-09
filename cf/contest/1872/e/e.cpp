#include <bits/stdc++.h>
#define g(i) (i & (i + 1))
#define h(j) (j | (j + 1))
using namespace std;
using ll = long long;
using vll = vector<ll>;
struct ft {
    vll a;
    int n;
    ft(vll &v) {
        n = v.size();
        a.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (v[i]) update(i);
        }
    }
    void update(int i) { for (; i < n; i = h(i)) a[i] = !a[i]; }
    void update(int i, int j) { update(i); update(j + 1); }
    int query(int i) {
        int ret = 0;
        for (; i >= 0; i = g(i) - 1) ret ^= a[i];
        return ret;
    }
    int query(int i, int j) {
        return query(j) ^ query(i - 1);
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll v(n); for (auto &i : v) cin >> i;
        ft ft(v);
        int q; cin >> q;
        while (q--) {
            int a; cin >> a;
            if (a == 1) {
                int l, r; cin >> l >> r; l--, r--;
                cout << "a" << endl;
                cout << ft.query(l, r);
                cout << "b" << endl;
            } else if (a == 2) {
                int g; cin >> g; g--;
                cout << "c" << endl;
                ft.update(g);
                cout << "d" << endl;
            }
        }
    }

    return 0;
}
