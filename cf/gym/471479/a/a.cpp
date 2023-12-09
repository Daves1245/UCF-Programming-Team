#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int s = min(a - 1, b + c);
        cout << 2 * s + 1 << endl;
    }
    return 0;
}
