#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << max(a + b + c, a * (b + c), (a + b) * c, a * b * c) << endl;
    return 0;
}

