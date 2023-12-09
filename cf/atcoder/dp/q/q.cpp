#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define _g(i) (i & (i + 1))
#define _h(j) (j | (j + 1))
struct ft {
    vll a;
    int n;
    ft(int n): n(n) {
        a.assign(n, 0);
    }
    ll query(int i) {
        ll ret = 0;
        for (; i > 0; i = _g(i) - 1) ret = max(ret, a[i]);
        return ret;
    }
    void update(int i, ll v) {
        for (; i < n; i = _h(i)) a[i] = max(a[i], v);
    }
};
int main() {
    int n; cin >> n;
    vll h(n); for (auto &i : h) cin >> i;
    vll a(n); for (auto &i : a) cin >> i;
    vll dp(n, 0);

    ft ft(n);

    for (int i = 0; i < n; i++) {
        dp[i] = ft.query(h[i] - 1) + a[i];
        ft.update(h[i], dp[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
