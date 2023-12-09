#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        int i;
        for (i = 1; i <= n; i++) {
            if ((n % i) != 0) break;
        }

        cout << i - 1 << endl;
    }

    return 0;
}
