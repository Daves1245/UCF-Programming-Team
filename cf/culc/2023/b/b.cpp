#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, h; cin >> n >> h;
    ll t = 0;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i + 1];
    int i = 0;
    int f = 0;
    int s = 0;
    while (!s && (i < n)) {
        if (i == 0 || !v[i + 1]) {
            i++;
        } else if (h >= 3) {
            t += h - 1;
            h %= 2;
            h++;
            i++;
        }

        if (v[i]) {
            h += v[i] + t;
            v[i] = 0;
        }

        f |= i == n;
        h--;
        t++;
        s |= h <= 0;
    }

    cout << (!s && f ? "YES" : "NO") << endl;
    return 0;
}
