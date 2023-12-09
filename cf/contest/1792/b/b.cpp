#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (!a) {
            cout << 1 << endl;
            continue;
        }

        int ans = a + min(b, c) * 2;
        int x = min(b, c);
        b -= x;
        c -= x;
    }

    return 0;
}
