#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> v(n); for (int &i : v) cin >> i;

        int mn = v[n - 1];
        ll cnt = 0;
        map<int, ll> m;
        queue<int> q;
        for (int i = n - 1; i >= 0; i--) q.push(v[i]);
        while (q.size()) {
            int e = q.front(); q.pop();
            while (e > mn) {

            }
        }

        cout << cnt << endl;
    }

    return 0;
}
