#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        vector<int> o, e;
        for (int i = 0; i < n; i++) {
            (v[i] % 2 ? o : e).push_back(v[i]);
        }

        sort(o.begin(), o.end());
        sort(e.begin(), e.end());

        /*
        for (auto i : o) cout << i << " ";
        cout << endl;
        for (auto i : e) cout << i << " ";
        cout << endl;
        */

        if ((o.size() == 0) || (e.size() == 0)) {
            cout << "YES" << endl;
            continue;
        }

        bool good = true;
        int j = 0, k = 0;
        for (int i = 0; (j < o.size() && k < e.size()); i++) {
            if (v[i] % 2) {
                good &= o[j++] < e[k];
            } else {
                good &= e[k++] < o[j];
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
