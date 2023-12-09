#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> v(m); for (auto &i : v) cin >> i;

        int cnt = 0, f = 1;
        for (int i = 0; i < m; i++) {
            f &= v[i] <= (n + k - 1) / k;
            cnt += (v[i] == ((n + k - 1) / k));
        }

        f &= cnt <= n % k + k * !(n % k);

        cout << (f ? "YES" : "NO") << endl;
    }

    return 0;
}
