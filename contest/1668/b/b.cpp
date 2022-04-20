#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<bool> chairs(m);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        bool good = true;
        int j = 0;
        for (int k = 0; k < n; k++) {
            if (chairs[j]) {
                chairs[j] = 10;
                good = false;
                break;
            }
            chairs[j] = true;

            for (int i = 1; i <= v[k]; i++) {
                int fw = (k + i) % m;
                int bw = (k + m - i) % m;
                if (chairs[fw]) {
                    chairs[fw] = 10;
                    good = false;
                    break;
                }
                if (chairs[bw]) {
                    chairs[fw] = 10;
                    good = false;
                    break;
                }
            }

            chairs[j] = true;
            j = (j + v[k]) % m;
        }

        for (auto i : chairs) {
            cout << i << " ";
        }
        cout << endl;
        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

