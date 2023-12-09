#include <bits/stdc++.h>
using namespace std;
#define check(a, b, c) ((((a <= b) && (b <= c)) || ((a >= b) && (b >= c))) && ((b - a) == (c - b)))
#define div(a, b) ((a % b) == 0)
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        bool f = 0;
        int d, e;

        d = c - b;
        e = b - d;
        f |= (e >= a) && check(e, b, c) && div(e, a);

        d = b - a;
        e = b + d;
        f |= (e >= c) && check(a, b, e) && div(e, c);

        d = (c - a) / 2;
        e = a + d;
        f |= (e >= b) && check(a, e, c) && div(e, b);

        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
