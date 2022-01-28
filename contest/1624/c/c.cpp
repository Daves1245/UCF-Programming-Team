/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> freq(n + 1, 0);
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] <= n) {
                freq[v[i]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[i] > n && freq[v[i]] > 1) {
                while (v[i] > n) {
                    v[i] /= 2;
                }
                int 
                while (freq[v[i]] > 1) {
                    v[i] /= 2;
                }
            }
        }

        bool fail = false;
        for (int i = 0; i < n; i++) {
            if (freq[i] != 1) {
                fail = true;
            }
        }

        cout << (fail ? "YES" : "NO") << endl;
    }
    return 0;
}

