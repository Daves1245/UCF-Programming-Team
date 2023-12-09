#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n); for (auto &i : v) cin >> i;
        unordered_map<int, int> m;
        auto cp = v;
        sort(cp.begin(), cp.end());
        for (int i = 0; i < n - 1; i++) m[cp[i]] = cp[i + 1];
        m[cp[n - 1]] = 1e9 + 7;
        int cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] != m[v[i]]) cnt++;
        }
        
        cout << (cnt <= k ? "Yes" : "No") << endl;
    }
    return 0;
}
