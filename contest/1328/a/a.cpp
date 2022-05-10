#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        if (a < b) cout << b - a << endl;
        else cout << b * (long long) (ceil((long double) a / b)) % a << endl;
    }
    return 0;
}

