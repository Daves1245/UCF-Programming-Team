#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        ll suf = n * (n + 1) / 2 - (a - 1) * a / 2; 
        bool neg = a < b;
        ll overlap;
        if (neg) {
            overlap = b / a;
        } else {
            overlap = a / b;
        }

        cout << suf - pre << endl;
    }
    return 0;
}
