#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> v(m); for (auto &i : v) cin >> i;
        bool f = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            f &= v[i] <= n / k;
            cnt += (n / k) == v[i];
        }

        f &= cnt <= (n % k);

        cout << (f ? "YES" : "NO") << endl;
    }

    return 0;
}
