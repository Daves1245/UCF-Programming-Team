#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; n--;
        int m = 1 << (31 - __builtin_clz(n));
        for (int j = m - 1; j >= 0; j--) {
            cout << j << " ";
        }
        for (int j = m; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
