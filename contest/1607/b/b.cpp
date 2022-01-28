#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // cout << "b = " << b << " % 4 == ";
        long long c = b;
        if (abs(a) % 2 == 0) {
            switch (b % 4) {
                case 0:
                    c = 0;
                    break;
                case 1:
                    c = -b;
                    break;
                case 2:
                    c = 1;
                    break;
                case 3:
                    c = b + 1;
                    break;
            }
        } else {
            switch (b % 4) {
                case 0:
                    if (b == 0) c = 0;
                    else c = 6;
                    break;
                case 1:
                    if (b == 1) c = 1;
                    else c = b + 6;
                    break;
                case 2:
                    if (b == 2) c = -1;
                    else c = 5;
                    break;
                case 3:
                    c = -b + 6;
                    break;
            }
        }
        cout << a + c << endl;
    }
}
