#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        vector<int> freq(2 * 1e5 + 10, 0);
        for (int i = 0; i < n; i++) cin >> v[i], freq[v[i]]++;
        sort(v.begin(), v.end());
        bool good = false;
        int l = 0, r = 0, ml = 0, mr = 0;
        int a, b;
        while (r < n) {
            if (r + freq[v[r]] < n && v[r] + 1 != v[r + freq[v[r]]]) {
                if (r - l >= mr - ml) {
                    a = v[l];
                    b = v[r];
                    ml = l;
                    mr = r;
                }

                l = r;
            }

            if (freq[v[r]] >= k) {
                if (r - l >= mr - ml) {
                    a = v[l];
                    b = v[r];
                    ml = l;
                    mr = r;
                }

                good = true;
            } else {
                l = r + freq[v[r]];
            }

            r += freq[v[r]];
        }

        if (good) {
            cout << a << " " << b << endl;
            cerr << l << " " << r << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
