#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    vector<bool> v(d, false);
    for (int i = 0; i <= d; i += k) v[i] = true;
    for (int i = 0; i <= d; i += l) v[i] = true;
    for (int i = 0; i <= d; i += m) v[i] = true;
    for (int i = 0; i <= d; i += n) v[i] = true;
    int c = 0;
    for (int i = 1; i <= d; i++) c += v[i];
    cout << c << endl;
    return 0;
}

