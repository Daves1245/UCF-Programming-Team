#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k && !(n == 0 && m == 0 && k == 0)) {
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }

        ll cur = n;
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            sum += cur;
            cur += v[i % k];
        }

        cout << sum << endl;
    }
    return 0;
}

