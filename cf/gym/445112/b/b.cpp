#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n); for ( auto &i : a ) cin >> i; for (auto &i : b) cin >> i;
        cout << accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL) - *max_element(b.begin(), b.end()) << endl;
    }

    return 0;
}
