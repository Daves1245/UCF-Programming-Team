/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll m; cin >> m;

        unordered_set<ll> seen;
        queue<pair<ll, string>> q; q.push(make_pair(3, "3"));
        while (!q.empty()) {
            auto [u, s] = q.front(); q.pop();
            if (seen.count(u)) continue;
            seen.insert(u);
            if (u % m == 0) {
                cout << s << endl;
                break;
            }

            ll ten = 10 * u % m;
            ll three = (10 * u + 3) % m;

            if (seen.count(ten) == 0)
                q.push(make_pair(ten, s + "0"));
            if (seen.count(three) == 0)Z
                q.push(make_pair(three, s + "3"));
        }
    }
    return 0;
}

