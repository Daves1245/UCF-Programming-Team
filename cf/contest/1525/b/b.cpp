#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        if (is_sorted(v.begin(), v.end())) {
            cout << 0 << endl;
        } else if ((v[0] == 1) || (v[n - 1] == n)) {
            cout << 1 << endl;
        } else if ((v[0] == n) && (v[n - 1] == 1)) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}
