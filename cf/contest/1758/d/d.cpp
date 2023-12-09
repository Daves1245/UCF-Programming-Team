#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long> v(n);
        if (n & 1) {
            for (long i = 0; i < n; i++) {
                v[i] = 1 + 2 + i + (n - 1) / 2;
            }
            v[0]--;
            v[n - 1]++;
            v[n - 2]++;
        } else {
            for (long i = 0; i < n / 2; i++) {
                v[i] = i + n / 2;
            }
            for (long i = 0; i < n / 2; i++) {
                v[i + n / 2] = 1 + i + n;
            }
        }

        for (auto i : v) cout << i << " "; cout << endl;
    }

    return 0;
}
