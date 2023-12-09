#include <bits/stdc++.h>
using namespace std;
bool square(int n) {
    bool ret = 0;
    for (int i = 0; i * i <= n; i++) {
        ret |= i * i == n;
    }
    return ret;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if ( !(n % 2) && square(n / 2)
||
            !(n % 4) && square(n / 4
                )) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
