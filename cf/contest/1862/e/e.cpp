#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> v(n); for (auto &i : v) cin >> i;
        using st = ll;
        priority_queue<st, vector<st>, greater<st>> pq;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                pq.push(v[i]);
            }
            if (pq.size() > m) pq.pop();
        }

        while (pq.top() - d * pq.size() <= 0) pq.pop();

        ll sum = 0;
        ll cnt = 1;
        while (pq.size()) {
            sum += pq.top() - d * cnt; cnt++;
            pq.pop();
        }
        cout << sum << endl;
    }
    return 0;
}
