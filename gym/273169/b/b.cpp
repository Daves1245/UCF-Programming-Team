/*
 * Author: medbar
 * Date: 2021-10-08
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

#define INF 1000000010LL

class segtree {
    public:
        int size;
        vll st;

        segtree(int n) {
            size = 1;
            while (size < n) size *= 2;
            st.assign(2 * size, INF);
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }

        ll query(int l, int r) {
            return query(l, r, 0, 0, size);
        }

        int lc(int i) {
            return 2 * i + 1;
        }

        int rc(int i) {
            return 2 * i + 2;
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
            /*
            printf("p %d\n", p);
            printf("lc p %d\n", lc(p));
            printf("rc p %d\n", rc(p));
            */
            ll lv = st[lc(p)];
            ll rv = st[rc(p)];
            st[p] = min(lv, rv);
        }

        ll query(int l, int r, int p, int i, int j) {
            if (j <= l || i >= r) return INF;
            if ((l <= i) && (j <= r)) return st[p];
            int m = (i + j) / 2;
            ll ls = query(l, r, lc(p), i, m);
            ll rs = query(l, r, rc(p), m, j);
            return min(ls, rs);
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    segtree st(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int j, v;
            cin >> j >> v;
            st.set(j, v);
        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
    }
    return 0;
}

