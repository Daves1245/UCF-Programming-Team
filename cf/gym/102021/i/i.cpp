#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> h(n); for (auto &i : h) cin >> i;
    vector<int> v(n); for (auto &i : v) cin >> i;
    if (h[0] > v[0]) {
        cout << 0 << endl;
        return 0;
    }
    int d = v[0] - h[0];
    bool f = 0;
    bool b = 0;
    int i;
    for (i = 0; !b && !f && (i < n); i++) {
        f |= h[i] + d > v[i];
        b |= h[i] + d < v[i];
        if (f || b) break;
    }
    if (f || (i >= n)) cout << d << endl;
    else cout << d + 1 << endl;
    return 0;
}
