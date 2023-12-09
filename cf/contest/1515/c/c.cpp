#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m >> x;
        vector<int> v(n); for (auto &i : v) cin >> i;
        using st = pair<int, int>;
        priority_queue<st, vector<st>, greater<st>> pq;
        for (int i = 1; i <= m; i++) {
            pq.push({0, i});
        }

        cout << "YES" << endl;
        for (int j = 0; j < n; j++) {
            auto [h, i] = pq.top(); pq.pop();
            cout << i << " ";
            pq.push({h + v[j], i});
        }
        cout << endl;
    }

    return 0;
}
