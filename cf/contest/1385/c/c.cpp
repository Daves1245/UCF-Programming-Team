#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        bool f = 0;
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            if (f && v[i] < v[i - 1]) {
                ans = i;
                break;
            }
            f |= v[i] > v[i - 1];
        }

        cout << ans << endl;
    }

    return 0;
}
