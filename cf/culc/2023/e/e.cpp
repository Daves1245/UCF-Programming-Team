#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll M = 1e9 + 7;
ll pow(int b, int p) {
    if (!p) return 1;
    ll x = pow(b, p / 2) % M;
    x = (x * x) % M;
    if (p & 1) x = (x * b) % M;
    return x;
}
int main() {
    string s; cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') ans = (ans + pow(2, n - (i + 1))) % M;
    }
    cout << ans << endl;
    return 0;
}
