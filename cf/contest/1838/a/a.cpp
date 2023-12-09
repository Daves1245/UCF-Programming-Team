#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        if (v[0] < 0) cout << v[0] << endl;
        else cout << v[n - 1] << endl;
    }

    return 0;
}
