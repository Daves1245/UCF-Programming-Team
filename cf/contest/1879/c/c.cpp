#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int M = 998244353;
ll fact(ll n) {
    if (!n || (n == 1)) return 1;
    else return n = ((n * fact(n - 1)) % M);
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<ll> v;
        ll c = 0;
        char l = s[0];
        for (int i = 0; i < n; i++) {
            if (s[i] == l) c++;
            else {
                l = s[i];
                v.push_back(c);
                c = 1;
            }
        }
        v.push_back(c);

        ll rest = n - (unique(s.begin(), s.end()) - s.begin());
        ll ans = 1;
        for (ll i : v) ans = (ans * i) % M;
        cout << rest << " " << (ans * fact(rest)) % M<< endl;
    }
    return 0;
}
