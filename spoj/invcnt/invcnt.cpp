/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

#define lsb(i) ((i) & -(i))

using namespace std;

using ll = long long;
using vi = vector<ll>;

struct fenwick {
    vi ft;
    vi v;
    fenwick(int n) {
        ft.resize(n + 1);
    }

    void build(vi arr) {
        v = arr;
        for (int i = 0; i < v.size(); i++) {
            update(i, v[i]);
        }
    }

    void update(int s){ {
        int i = s;
        for (; i < ft.size(); i += lsb(i)) {
            if (v[i] < vi[s]) {
                ft[i]++;
            }
        }
    }

    void ru(int i, int j, int v) {
        update(i, v);
        update(j + 1, -v);
    }

    ll query(int i) {
        ll ret = 0;
        for (; i; i -= lsb(i)) {
            ret += ft[i];
        }
        return ret;
    }

    ll query(int i, int j) {
        return query(j) - query(i - 1);
    }
};

int main() {
    fenwick ft;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fenwick ft(n);
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ft.build(v);
        cout << ft.query(n) << endl;
    }
    return 0;
}

