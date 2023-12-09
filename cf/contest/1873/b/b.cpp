#include <bits/stdc++.h>
using namespace std;
int prod(vector<int> &v) {
    int ret = 1;
    for (auto i : v) ret *= i;
    return ret;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;

        int mx = 0;
        for (int i = 0; i < n; i++) {
            v[i]++;
            mx = max(mx, prod(v));
            v[i]--;
        }

        cout << mx << endl;
    }

    return 0;
}
