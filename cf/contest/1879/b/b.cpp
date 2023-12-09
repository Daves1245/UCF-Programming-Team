#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n); for (auto &i : a) cin >> i; for (auto &i : b) cin >> i;
        cout << min(*min_element(a.begin(), a.end()) * n + accumulate(b.begin(), b.end(), 0LL), 
             *min_element(b.begin(), b.end()) * n + accumulate(a.begin(), a.end(), 0LL)) << endl;
    }
    return 0;
}
