#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; m--; vector<ll> v(n); for (auto &i : v) cin >> i;
        vector<ll> ps(n); ps[0] = v[0];
        for (int i = 1; i < n; i++) ps[i] = v[i] + ps[i - 1];

        priority_queue<ll> pq;
        int cnt = 0;
        ll offset = 0;

        for (int i = m; i >= 0; i--)  {
            while (ps[i] < ps[m]) {
                offset -= pq.top();
                ps[m] -= pq.top(); pq.pop();
                cnt++;
            }
            pq.push(2 * v[i]);
        }

        priority_queue<ll, vector<ll>, greater<ll>> mpq;
        for (int i = m + 1; i < n; i++) {
            mpq.push(2 * v[i]);
            while (ps[i] + offset < ps[m]) {
                ps[m] += mpq.top(); mpq.pop();
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
