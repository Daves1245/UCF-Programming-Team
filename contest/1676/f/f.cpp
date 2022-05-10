#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n), freq(2 * 1e5 + 10, 0);
        for (int i = 0; i < n; i++) cin >> v[i], freq[v[i]]++;
        sort(v.begin(), v.end());
        int l = 0, r = 0, ml = -1, mr = -1;
        int a = -1, b = -1;
        for (int i = 0; i < n; i += freq[v[i]]) {
            if (v[i] < k) {
                if (r - l >= mr - ml) {
                    ml = l;
                    mr = r;
                    a = v[l];
                    b = v[r];
                }
                i += freq[v[i]];
                l = i;
                r = i + freq[v[i]];
            } else {
                r += freq[v[r]];
            }
        }

        if (r - l >= mr - ml) {
            ml = l;
            mr = r;
            a = v[l];
            b = v[r];
        }

        cout << a << " " << b << endl;
    }
    return 0;
}

