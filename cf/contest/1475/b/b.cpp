#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool f = 0;
        for (int i = 0; !f && i <= n; i += 2020) for (int j = 0; !f && j <= n - i; j += 2021) f |= i + j == n;
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
