#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, d; cin >> n >> m >> d;
        int c = 0;
        vll v(m); for (auto &i : v) {
            cin >> i;
            c += ((i - 1) % d) != 0;
        }
        cout << c << endl;
    }
    return 0;
}
