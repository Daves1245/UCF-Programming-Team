#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        while (n != 1) {
            if ((n % 3)) {
                cnt = -1;
                break;
            }
            cnt++;
            if (!(n % 6)) {
                n /= 6;
            } else {
                n *= 2;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
