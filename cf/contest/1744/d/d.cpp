#include <bits/stdc++.h>
using namespace std;
int msb(int n) {
    int ret = 0;
    while (n) ret++, n >>= 1;
    return ret;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        vector<int> twos;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            twos.push_back(__builtin_ctz(i + 1));
            while (!(v[i] & 1)) cnt++, v[i] >>= 1;
        }

        if (cnt >= n) {
            cout << 0 << endl;
            continue;
        }

        if (cnt + accumulate(twos.begin(), twos.end(), 0LL) < n) {
            cout << -1 << endl;
            continue;
        }
        sort(twos.begin(), twos.end(), greater<int>());
        vector<int> ps(twos.size() + 1, 0);
        for (int i = 0; i < twos.size(); i++) ps[i + 1] = ps[i] + twos[i];
        // for (auto i : ps) cout << i << " "; cout << endl;

        cout << lower_bound(ps.begin(), ps.end(), n - cnt) - ps.begin() << endl;
    }

    return 0;
}
