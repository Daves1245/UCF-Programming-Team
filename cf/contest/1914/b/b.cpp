#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> v(n); for (int i = 0; i < n; i++) v[i] = i + 1;
        sort(v.begin(), v.end(), greater<int>());
        sort(v.begin(), v.begin() + m + 1);
        for (auto i : v) cout << i << " "; cout << endl;
    }

    return 0;
}
