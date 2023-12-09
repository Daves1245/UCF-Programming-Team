#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; 
        char c; cin >> c;
        string v; cin >> v;
        bool f = 1;
        for (auto i : v) f &= (i == c);
        if (f) {
            cout << 0 << endl;
            continue;
        }

        bool g = 0;
        for (int i = 2; i <= n; i++) {
            bool f = 1;
            for (int j = i - 1; j < n; j += i) {
                f &= v[j] == c;
            }
            if (f) {
                g = 1;
                cout << 1 << endl;
                cout << i << endl;
                break;
            }
        }
        if (g) continue;

        cout << 2 << endl;
        cout << n << " " << n - 1 << endl;
    }
    return 0;
}
