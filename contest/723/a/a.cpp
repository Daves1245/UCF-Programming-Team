#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int m = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        m = min(m, abs(i - a) + abs(i - b) + abs(i - c));
    }
    cout << m << endl;
    return 0;
}

