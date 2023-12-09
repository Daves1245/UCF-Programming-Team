#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> v(n); for (auto &i : v) cin >> i;
        string name = "vika";
        int k = 0;
        bool good = false;
        for (int i = 0; !good && i < m; i++) {
            bool match = false;
            for (int j= 0; !match && j < n; j++) {
                if (tolower(v[j][i]) == name[k]) {
                    k++;
                    match = true;
                    if (k >= name.size()) good = true;
                }
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}
