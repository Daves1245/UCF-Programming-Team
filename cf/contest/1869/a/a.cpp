#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        int x = 2 * (n % 2);
        cout << 2 + x << endl;
        for (int i = 0; i < 2; i++) {
            cout << 1 << " " << 2 * (n / 2) << endl;
        }
        if (x) {
            cout << n - 1 << " " << n << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
    return 0;
}
