#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int n = 1;
        while (l * (1 << n) < r) n++;
        cout << n << " " << (r / (1 << (n - 1))) - l + 1 + (r / ((n - 2) * 3)) * (n - 1) - l + 1 << endl; 
    }

    return 0;
}
