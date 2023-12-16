#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> a = v;
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
        vector<ll> ans(n, -1);
        for (int i = 1; i <= n; i++) {
            if (v[i - 1] > ps[i]) {
                for (int j = i - 1; (ans[j] == -1) && j >= 0; j--) {
                    ans[j] = i;
                }
            }
        }
        int k = n - 1;
        while ((ans[k] == -1) && (k >= 0)) ans[k--] = n;
        cout << "ans ";
        for (auto i : ans) cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] - i << " ";
        }
        cout << endl;
    }

    return 0;
}

