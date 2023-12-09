#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        unordered_map<int, ll> m;
        for (int i = 0; i < n; i++) v[i] -= i + 1, m[v[i]]++;
        ll tot = 0;
        for (auto [k, v] : m) if (v >= 2) tot += (v - 1) * v / 2;
        cout << tot << endl;
    }
    return 0;
}
