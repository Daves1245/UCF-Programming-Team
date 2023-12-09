#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unordered_map<int, ll> run;

        queue<int> a, b;

        ll best = 0;
        for (int i = 0; i < n; i++) {
            int e; cin >> e;
            a.push(e);
        }

        for (int i = 0; i < n; i++) {
            int e; cin >> e;
            b.push(e);
        }

        while (a.size() || b.size()) {
            ll pa = (a.size() ? a.front() : -1);
            ll pb = (b.size() ? b.front() : -1);

            ll ca = 0;
            while (a.size() && (a.front() == pa)) {
                ca++;
                a.pop();
            }
            ll cb = 0;
            while (b.size() && (b.front() == pb)) {
                cb++;
                b.pop();
            }

            if (pa == pb) best = max(best, ca + cb);
            else best = max({best, ca, cb});
        }

        cout << best << endl;
    }

    return 0;
}
