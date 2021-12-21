/*
 * Author: medbar
<<<<<<< HEAD
 * Date: 2021-10-07
=======
 * Date: 2021-10-06
>>>>>>> 1cfc31f1140266816e18bc579e0e37c22f79c1e4
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

<<<<<<< HEAD
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
=======
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

int st[4 * 100000 + 10];

int lc(int p) {
    return 2 * p;
}

int rc(int p) {
    return 2 * p + 1;
}

void build(int p, int l, int r) {
    if (l == r) {
        return;
    }
    st[lc(p)]
}
>>>>>>> 1cfc31f1140266816e18bc579e0e37c22f79c1e4

int main() {
    int n, m;
    cin >> n >> m;

<<<<<<< HEAD
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.set(i, v);
    }

    while (m--) {
=======
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }

    build(0, n - 1);

    for (int i = 0; i < m; i++) {
>>>>>>> 1cfc31f1140266816e18bc579e0e37c22f79c1e4
        int q;
        cin >> q;
        if (q == 1) {
            int i, v;
            cin >> i >> v;
<<<<<<< HEAD
            st.set(i, v);
        } else if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << endl;
        }
    }

=======
            update(i, v);
        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 0, n - 1) << endl;
        }
    }
>>>>>>> 1cfc31f1140266816e18bc579e0e37c22f79c1e4
    return 0;
}

