#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        sort(v.begin(), v.end());
        for (int i = 0; i < n / 2; i++) {
            cout << v[i + n / 2] << " " << v[0] << endl;
        }
    }
    return 0;
}
