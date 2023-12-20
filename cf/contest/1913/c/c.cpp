#include <bits/stdc++.h>
using namespace std;
int msb(int n) {
    int ret = 0;
    while (n) {n >>= 1; ret++;}
    return ret;
}
int main() {
    int t; cin >> t;
    vector<int> freq(32, 0);

    while (t--) {
        int a, b; cin >> a >> b;
        if (a == 2) {
            for (int i = 30; i >= 0; i--) {
                b -= min(b / (1 << i), freq[i]) * (1 << i);
            }
            cout << (!b ? "YES" : "NO") << endl;
        } else {
            freq[b]++;
        }
    }

    return 0;
}
