#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
int main() {
    int n; cin >> n;

    ll INF = 1e13;
    vector<int> v(n); for (auto &i : v) cin >> i;
    vector<vll> dp(n, vll(n));
    vector<vi> opt(n, vi(n));
    vll ps(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + v[i];
        opt[i][i] = i;
        dp[i][i] = 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ll mn = INF;
            for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                ll cost = ps[j + 1] - ps[i] + dp[i][k] + dp[k + 1][j];
                if (cost < mn) {
                    opt[i][j] = k;
                    mn = cost;
                }
            }
            dp[i][j] = mn;
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
