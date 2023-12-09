#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int k = v[n - 1];
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] > k) {
                k = v[i];
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
