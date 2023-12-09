#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a,  b, c; cin >> a >> b >> c;
        bool f = (a == b + c) || (b == a + c) || (c == a + b);
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
