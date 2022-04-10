#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a, b, c, d;
        switch (n % 4) {
            case 0:
                a = b = c = d = (n / 4);
                break;
            case 1:
                a = 2 * (n / 4) - 1;
                b = 2 * (n / 4);
                c = d = 1;
                break;
            case 2:
                a = 2 * (n / 4) - 1;
                b = 2 * (n / 4) + 1;
                c = d = 1;
                break;
            case 3:
                a = 2 * (n / 4);
                b = 2 * (n / 4) + 1;
                c = d = 1;
                break;
        }

        cout << a << " " << b << " " << c << " " << d << endl;
    }
    return 0;
}

