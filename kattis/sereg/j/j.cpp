/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    int ans = 0;
    vector<pair<int, int>> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < t - 1; i++) {
        ans = max(ans, (v[i + 1].second - v[i].second) / (v[i + 1].first - v[i].first));
    }

    cout << ans << endl;
    return 0;
}

