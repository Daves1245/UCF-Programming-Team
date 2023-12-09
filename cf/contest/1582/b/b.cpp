#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n); for (auto &i : v) cin >> i;
        int oc = 0, zc = 0;
        for (auto i : v) oc += i == 1, zc += i == 0;
        cout << oc * (1LL << zc) << endl;
    }
    return 0;
}
