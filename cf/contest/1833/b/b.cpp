#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n); for (auto &i : a) cin >> i; for (auto &i : b) cin >> i;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());
        sort(b.begin(), b.end());

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            auto [x, y] = v[i];
            m[y] = b[i];
        }

        for (int i = 0; i < n; i++) {
            cout << m[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
