#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        for (int i = 0; i < n; i++) {
            int steps = 0;
            int ma = v[i];
            for (int j = i - 1; j >= 0; j--) {
                if (v[j] > ma) {
                    ma = v[j];
                    steps++;
                }
            }

            ma = v[i];
            for (int j = i + 1; j < n; j++) {
                if (v[j] > ma) {
                    ma = v[j];
                    steps++;
                }
            }
            cout << steps << " ";
        }
        cout << endl;
    }

    return 0;
}
