#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n); for (auto &i : v) cin >> i;
        bool looped = 0, reached = 0;
        int i = n - 1;
        int cnt = 0;
        while (!looped && !reached) {
            int nxt = (i + v[i]) % n;
            cnt++;
            if (cnt >= k) { reached = 1; break; }
            looped |= v[nxt] == v[i];
            if (looped) break;

        }

        cout << (!looped && reached ? "Yes" : "No") << endl;
    }

    return 0;
}
