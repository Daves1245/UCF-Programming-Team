#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 7;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int ans[3];
        int k = 0;
        for (int i = 0; i < n; i++) {
            bool f = false;
            for (int j = 0; j < i; j++) {
                for (int k = j + 1; k < i; k++) {
                    if (v[j] + v[k] == v[i]) {
                        f = true;
                    }
                }
            }
            if (!f) cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

