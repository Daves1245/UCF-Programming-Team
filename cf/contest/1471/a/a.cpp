#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x; vector<int> v(n); for (auto &i : v) cin >> i;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((v[i] < x) && (v[i] + v[i + 1] > x)) cnt++, i += 2;
        }
        cout << cnt << endl;
    }
    return 0;
}
