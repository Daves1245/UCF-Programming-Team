#include <bits/stdc++.h>

using namespace std;

using vi = vector<long long>;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<ll>());
        for (int i = 1; i < n; i++) v[i] += v[i - 1];
        for (int i = 0; i < q; i++) {
            ll tmp; cin >> tmp;
            if (tmp > v[v.size() - 1]) {
                cout << -1 << endl;
                continue;
            }
            cout << distance(v.begin(), lower_bound(v.begin(), v.end(), tmp)) + 1 << endl;
        }
    }
    return 0;
}

