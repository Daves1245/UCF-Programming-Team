#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ma = 500;
        vector<pair<int, int>> v(n); for (auto &[a, b] : v) cin >> a >> b;
        for (auto [d, s] : v) {
            ma = min(ma, d + ((s - 1) / 2));
        }
        cout << ma << endl;
    }
    return 0;
}
