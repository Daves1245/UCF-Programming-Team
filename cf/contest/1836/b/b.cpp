#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n, k, g; cin >> n >> k >> g;
        ll x = k * g / n;
        ll res = 0;
        if (x % g >= g / 2) {
            cout <<"yipee" << endl;
        } else {
            cout << n * g << endl;
        }
    }

    return 0;
}
