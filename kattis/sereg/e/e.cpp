/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int k = 0;
    int ans = 0;
    while (k < n) {
        ans++;
        for (int i = 1; i <= 100; i++) {
            if (v[k] == i) k++;
        }
    }
    cout << ans;
    return 0;
}

