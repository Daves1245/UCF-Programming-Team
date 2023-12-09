#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        vector<int> v(n); v[0] = a, v[n - 1] = b;
        bool f = false;
        int c = n;
        int k = 1;
        for (int i = 0; i < n; i++) {
            if ((c == a) || (c == b)) {
                c--;
                continue;
            }
            v[k++] = c--;
            if (c < 1) {
               c = n;
            }
        }
        f = true;
        for (int i = 0; i < n / 2; i++) f &= a <= v[i];
        for (int i = n / 2; i < n; i++) f &= b >= v[i];
        if (!f) cout << -1 << endl;
        else {for (auto i : v) cout << i << " "; cout << endl;}
    }
    return 0;
}
