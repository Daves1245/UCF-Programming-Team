#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    int f = 0;
    /*
    for (int i = 1; i <= 50; i++) {
        cout << i << ": ";
        bool f = 0;
        for (int a = 1; !f && a < i; a++) {
            if (!(a % 3)) continue;
            for (int b = a + 1; !f && b < i; b++) {
                if (!(b % 3)) continue;
                for (int c = b + 1; !f && c < i; c++) {
                    if (!(c % 3)) continue;
                    if (a + b + c == i) f = 1, cout << a << " " << b << " " << c;
                }
            }
        }
        cout << endl;
    }
    */

    while (t--) {
        int n; cin >> n;
        if (n <= 6 || n == 9) {
            cout << "NO" << endl;
            continue;
        }

        int a = 1, b = 2, c = n - 3;
        if (!(n % 3)) b += 2, c -= 2;
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
