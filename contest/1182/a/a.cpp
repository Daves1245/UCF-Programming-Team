#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(int a, int b) {
    if (b == 1) {
        return a;
    }
    return a * pow(a, b - 1);
}

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << pow(2, n / 2) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

