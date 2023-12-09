#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> v(2 * n); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        bool good = true;
        for (int i = 0; i < n; i++) good &= v[i + n] >= v[i] + x;
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}
