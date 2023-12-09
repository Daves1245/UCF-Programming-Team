#include <bits/stdc++.h>
using namespace std;
int msb(int n) {
    int ret = 0;
    while (n >>= 1) ret++;
    return ret;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int cnt = 1;
        if (k >= 32) {
            cout << n + 1 << endl;
            continue;
        }
        cout << 1 + min(n, (1 << k) - 1) << endl;
    }
    return 0;
}
