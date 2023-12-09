#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        int f = 1;
        for (int i = 0; f && i < n; i++) {
            if (!is_sorted(v.begin(), v.begin() + min(n, (1 << i)))) {
                f = 0;
            } else {
                fill(v.begin(), v.begin() + min(n, (1 << i)), 0);
            }
        }

        cout << (f ? "YES" : "NO") << endl;
    }

    return 0;
}
