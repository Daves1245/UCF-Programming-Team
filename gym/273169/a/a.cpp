/*
 * Author: medbar
 * Date: 2021-10-07
 */

#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

struct segtree {
    int size;
    vll st;
    
    int lc(int n) {
        return 2 * n + 1;
    }
    
    int rc(int n) {
        return 2 * n + 2;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        st.assign(2 * size, 0LL);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    private:
    void set(int i, int v, int p, int l, int r) {
        if (r - l == 1) {
            st[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i < m) set(i, v, lc(p), l, m);
        else set(i, v, rc(p), m, r);
        st[p] = st[lc(p)] + st[rc(p)];
    }

    ll query(int l, int r, int p, int i, int j) {
        if (i >= r || l >= j) return 0;
        if ((i >= l) && (j <= r)) return st[p];
        int m = (i + j) / 2;
        ll ls = query(l, r, lc(p), i, m);
        ll rs = query(l, r, rc(p), m, j);
        return ls + rs;
    }

    public:
    ll sum(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }

    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }

    return 0;
}

