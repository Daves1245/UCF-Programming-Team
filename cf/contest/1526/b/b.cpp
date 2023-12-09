#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<ll> ps(n + 1, 0); for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + v[i];
    }

    return 0;
}
