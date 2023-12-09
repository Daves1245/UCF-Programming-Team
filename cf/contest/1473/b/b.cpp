#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int n = a.size(), m = b.size();
        string c = "", d = "";
        for (int i = 0; i < lcm(n, m) / n; i++) {
            c += a;
        }
        for (int i = 0; i < lcm(n, m) / m; i++) {
            d += b;
        }
        if (c == d) {
            cout << c << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
