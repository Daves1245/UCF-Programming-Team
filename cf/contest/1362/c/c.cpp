#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << 2 * n - __builtin_popcountll(n) << endl;
    }
    return 0;
}
