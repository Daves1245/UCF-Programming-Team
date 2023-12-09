#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> where(n + 1); for (int i = 0; i < n; i++) where[v[i]] = i;

        int l = (n + 1) / 2, r = (n + 2) / 2;
        while ((l == r) || (l > 0) && (r <= n) && (where[l] < where[l + 1]) && (where[r - 1] < where[r])) {
            l--;
            r++;
        }

        cout << (n - (r - l) + 1) / 2 << endl;
    }
    return 0;
}
