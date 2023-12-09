#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    int N = (1 << 30);
    while (t--) {
        int n; cin >> n;
        int a = 0, b = 0;
        for (int i = 0; i < n - 2; i++) {
            a ^= i;
            b ^= i + 1;
        }

        if (a) {
            for (int i = 0; i < n - 2; i++) {
                cout << i << " ";
            }
            cout << N << " " << (a ^ N) << endl;
        } else {
            for (int i = 1; i <= n - 2; i++) {
                cout << i << " ";
            }
            cout << N << " " << (b ^ N) << endl;
        }
    }

    return 0;
}
