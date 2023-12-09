#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> b(k), degb(n), g(k), degg(m);
        for (auto &i : b) cin >> i, i--, degb[i]++;
        for (auto &i : g) cin >> i, i--, degg[i]++;

        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += k - degb[b[i]] - degg[g[i]] + 1;
        }

        cout << sum / 2 << endl;
    }
    return 0;
}
