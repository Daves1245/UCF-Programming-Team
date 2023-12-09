#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        vector<int> psa(n + 1, 0), psb(n + 1, 0);
        for (int i = 0; i < n; i++) psa[i + 1] = psa[i] + a[i];
        for (int i = 0; i < n; i++) psb[i + 1] = psb[i] + b[i];

        int best = INT_MAX;
        for (int i = 1; i <= n; i++) best = min(best, max(psa[n] - psa[i], psb[i - 1]));

        cout << best << endl;
    }

    return 0;
}
