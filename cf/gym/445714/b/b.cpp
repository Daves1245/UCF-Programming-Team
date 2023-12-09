#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> ans(n); for (int i = 0; i < n; i++) ans[i] = i + 1;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            if (v[i] == ans[i]) swap(ans[i], ans[i + 1]);
        }

        if (ans[n - 1] == v[n - 1]) {
            swap(ans[n - 1], ans[n - 2]);
        }

        for (auto i : ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}
