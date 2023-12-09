#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
    if (!(n % 2)) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (!(n % i)) return 0;
    }
    return 1;
}
int main() {
    int t; cin >> t;
    vector<string> ans = {"Ashishgup", "FastestFinger"};
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << ans[1] << endl;
            continue;
        }

        if (n == 2) {
            cout << ans[0] << endl;
            continue;
        }

        if (n % 2) {
            cout << ans[0] << endl;
            continue;
        }

        if (!(n & (n - 1))) {
            cout << ans[1] << endl;
            continue;
        }

        if (prime(n / 2)) {
            cout << ans[1] << endl;
            continue;
        }

        cout << ans[0] << endl;
    }

    return 0;
}
