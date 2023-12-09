#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pt(i) (((i) & ((i) - 1)) == 0)
int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        if (!(a % b)) {
            cout << 0 << endl;
            continue;
        }
        a %= b;

        ll d = gcd(a, b);
        b /= d;
        a /= d;
        if (b & (b - 1)) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        while (a < b) {
            a <<= 1;
            cnt <<= 1;
        }

        cout << cnt + 1 << endl;
    }
    return 0;
}
