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

#define INF 1000000010

class segtree {
    public:
        vii st;
        int size;

        segtree(int n) {
            size = 1;
            while (size < n) size *= 2;
            st.assign(2 * size, ii(INF, 1));
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }

        ii query(int l, int r) {
            return query(l, r, 0, 0, size);
        }

        int lc(int n) {
            return 2 * n + 1;
        }

        int rc(int n) {
            return 2 * n + 2;
        }

    private:
        void set(int i, int v, int p, int l, int r) {
            if (l > r) return;
            if (r - l == 1) {
                st[p].first = v;
                st[p].second = 1;
                return;
            }

            int m = (l + r) / 2;
            if (i < m) {
                set(i, v, lc(p), l, m);
            } else {
                set(i, v, rc(p), m, r);
            }

            ii ls = st[lc(p)];
            ii rs = st[rc(p)];

            st[p] = min(ls, rs);
            if (ls.first == rs.first) {
                st[p].second = ls.second + rs.second;
            }
        }

        ii query(int l, int r, int p, int i, int j) {
            if (i >= r || j <= l) return ii(INF, 0);
            if ((l <= i) && (j <= r)) return st[p];
            int m = (i + j) / 2;
            ii ls = query(l, r, lc(p), i, m);
            ii rs = query(l, r, rc(p), m, j);
            ii ret = min(ls, rs);
            if (ls.first == rs.first) {
                ret.second = ls.second + rs.second;
            }
            return ret;
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

    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            ii res = st.query(l, r);
            cout << res.first << " " << res.second << endl;
        }
    }
    return 0;
}

