#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        for (int i = 1; i < n - 1; i++) {
            v[i] = min(v[i - 1], v[i + 1]);
        }
    }
}
