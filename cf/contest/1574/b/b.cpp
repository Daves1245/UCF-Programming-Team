#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, n; cin >> a >> b >> c >> n;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if ((n > a + b + c - 3) || (n < c - 1 - (a + b))) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
