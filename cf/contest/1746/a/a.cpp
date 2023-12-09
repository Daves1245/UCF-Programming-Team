#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        bool f = 0;
        vector<int> v(n); for (auto &i : v) cin >> i, f |= i == 1;
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
