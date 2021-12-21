/*
 * Author: medbar
 * Date: 2021-10-06
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

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class segtree {
    public:
        vi a, st, lazy;
        int n;

        int lc(int n) { return n << 1; }
        int rc(int n) { return (n << 1) + 1; }

        void build(int p, int l, int r) {
            if (l == r) {
                st[l] = a[p];
                return;
            }
            int m = (l + r) / 2;
            build(lc(p), l, m);
            build(rc(p), m + 1, r);
        }

        void propogate(int p, int i, int j) {
            if (lazy[p] != -1) {
                if (i == j)
                    st[p] = lazy[p];
                else {
                    lazy[lc(p)] = lazy[rc(p)] = lazy[p];
                }
                lazy[p] = -1;
            }
        }

        void update(int p, int l, int r, int i, int j, int val) {
            propogate(p, i, j);
            if (i > j || j < l || i > r) {
                return;
            }

            if ((l <= i) && (j <= r)) {
                lazy[p] = val;
                propogate(p, i, j);
                return;
            }

            int m = (l + r) / 2;
            update(lc(p), l, r, i, , val);
            update(rc(p), l, r, m, j, val);
        }

        segtree(int n) {
            a.resize(n);
            st.resize(4 * n);
            lazy.resize(n);
            for (int i = 0; i < n; i++) {
                a[i] = i;
                lazy[i] = -1;
            }
        }

        segtree(const vi &og) : segtree((int) og.size()) {
            a = og;
            build(1, 0, n - 1);
        }

        int query(int p, int l, int r, int i, int j) {
            propogate(p, i, j);
            if (i > j) {
                return -1;
            }
            if ((l <= i) && (j <= r)) {
                return (lazy[p] != -1) ? lazy[p] : st[p];
            }
            int m = (l + r) / 2;
            int left = query(lc(p), l, r, i, m);
            if (left != -1) return left;
            return query(rc(p), l, r, m + 1, j);
        }

        void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }
};

int main() {
    int n, m;
    cin >> n >> m;

    segtree st(n);

    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        st.update(l, r, v);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", st.query(0, i, i, 0, n - 1));
    }
    printf("\n");

    return 0;
}
