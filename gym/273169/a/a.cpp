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

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }

    build(0, n - 1);

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int i, v;
            cin >> i >> v;
            update(i, v);
        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r, 0, n - 1) << endl;
        }
    }
    return 0;
}

