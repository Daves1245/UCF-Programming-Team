#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int m = n - 3;

    for (int i = 4; i * i <= n; i++) {
        if (m % i == 0 && i > 3) {
            cout << i << endl;
            return 0;
        }
    }

    for (int i = 3; i > 0; i--) {
        if (m % i == 0 && m / i > 3) {
            cout << m / i << endl;
            return 0;
        }
    }

    return 0;
}

