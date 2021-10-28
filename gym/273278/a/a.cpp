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

struct item {
    ll seg, pref, suff, sum;
};

ll maximum(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

class segtree {
    public:
        vector<item> st;
        int size;

        segtree(int n) {
            size = 1;
            while (size < n) size *= 2;
            st.assign(2 * size, IDENTITY);
        }

        void set(int i, int v) {
            set(i, v, 0, 0, size);
        }

        item query(int l, int r) {
            return query(l, r, 0, 0, size);
        }

        int lc(int n) {
            return 2 * n + 1;
        }

        int rc(int n) {
            return 2 * n + 2;
        }

        item IDENTITY = {0, 0, 0, 0};

        item single(int v) {
            if (v < 0) {
                return {0, 0, 0, v};
            }
            return {v, v, v, v};
        }

        item merge(item a, item b) {
            return {
                maximum(a.seg, b.seg, a.suff + b.pref),
                max(a.pref, a.sum + b.pref),
                max(b.suff, b.sum + a.suff),
                a.sum + b.sum
            };
        }

    private:
        void set(int i, int v, int p, int l, int r) {
            if (l > r) return;
            if (r - l == 1) {
                st[p] = single(p);
                return;
            }

            int m = (l + r) / 2;
            if (i < m) {
                set(i, v, lc(p), l, m);
            } else {
                set(i, v, rc(p), m, r);
            }

            st[p] = merge(st[lc(p)], st[rc(p)]);
        }

        item query(int l, int r, int p, int i, int j) {
            if (i >= r || j <= l) return IDENTITY;
            if ((l <= i) && (j <= r)) return st[p];
            int m = (i + j) / 2;
            return merge(query(l, r, lc(p), i, m), query(l, r, rc(p), m, j));
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

    for (int j = 0; j < m; j++) {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        item res = st.query(0, n);
        cout << res.seg << endl;
    }
    return 0;
}
