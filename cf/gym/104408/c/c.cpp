#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> v(n);
        for (auto &i : v) cin >> i;
        vector<int> c(n, 0);

        int ops = 0;

        for (int i = m - 1; i + 1; i--) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                int bit = (v[j][i] - '0' + c[j]) % 2;
                cnt += bit;
            }

            if (cnt <= n / 2) {
                ops += cnt;
                for (int j = 0; j < n; j++) {
                    int bit = (v[j][i] - '0' + c[j]) % 2;
                    if (bit) {
                        c[j]++;
                        // cout << "flip " << j + 1 << endl;
                    }
                }
            } else {
                ops += n - cnt;
                for (int j = 0; j < n; j++) {
                    int bit = (v[j][i] - '0' + c[j]) % 2;
                    if (!bit) {
                        c[j]++;
                        // cout << "flip " << j + 1 << endl;
                    }
                }
            }
        }

        cout << ops << endl;
        for (int i = 0; i < n; i++) {
            // cout << c[i] << endl;
        }
        // cout << endl;
    }

    return 0;
}
