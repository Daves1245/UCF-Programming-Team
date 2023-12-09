#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int ma = min(a, b);
        cout << min(ma, (a + b + c) / 3) << endl;
    }

    return 0;
}
