#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 2; i < 32; i++) {
            if ((n % ((1 << i) - 1)) == 0) {
                cout << n / ((1 << i) - 1) << endl;
                break;
            }
        }
    }
    return 0;
}
