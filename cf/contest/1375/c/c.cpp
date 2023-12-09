#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        cout << (v[0] < v[n - 1] ? "YES" : "NO") << endl;
    }
    return 0;
}
