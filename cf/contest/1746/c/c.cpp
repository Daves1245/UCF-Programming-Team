#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[v[i] - 1] = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (p[v[i] - 1] > i) cout << 1 << " ";
            else cout << p[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
