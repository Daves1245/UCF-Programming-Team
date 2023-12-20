#include <bits/stdc++.h>
using namespace std;
using ll = int;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k; vector<ll> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        for (int i = 1; i < n; i++) b[i] = max(b[i], b[i - 1]);
        int mx = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (k >= i + 1) 
                mx = max(mx, sum + b[i] * (k - i - 1));
        }

        cout << mx << endl;
    }

    return 0;
}
