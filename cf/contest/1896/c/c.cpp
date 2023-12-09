#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;

        vector<int> a(n); for (auto &i : a) cin >> i;
        vector<int> b(n); for (auto &i : b) cin >> i;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        cout << "n " << n << " x " << x << endl;
        cout << "a ";
        for (auto i : a) cout << i << " "; cout << endl;

        cout << "b ";
        for (auto i : b) cout << i << " "; cout << endl;

        int s = 1;
        for (int i = 0; i < x; i++) {
            cout << a[n - x + i] << " > " << b[i] << endl;
            s &= a[n - 1 - x + i] > b[i];
        }
        for (int i = 0; i < n - x; i++) {
            cout << a[i] << " <= " << b[n - x + i] << endl;
            s &= a[i] <= b[n - 1 - x + i];
        }

        cout << (s ? "YES" : "NO") << endl;
    }

    return 0;
}
