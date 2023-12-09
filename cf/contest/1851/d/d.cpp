#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> ps(n - 1); for (auto &i : ps) cin >> i;
        vector<ll> v(n - 1);
        set<ll> s;
        v[0] = ps[0];
        for (int i = 1; i < n - 1; i++) {
            v[i] = ps[i] - ps[i - 1];
            s.insert(v[i]);
        }

        bool good = s.size() == n - 3;
        cout << "A " << good << endl;
        sort(v.begin(), v.end());

        int k = 0;
        vector<int> missing(3);
        int outlier = -1, dupno = -1;

        if (v[0] != 1) {
            missing[k] = 1;
            k++;
        }

        if (v[n - 1] > n) {
            outlier = v[n - 1];
        }

        for (int i = 1; good && i < n - 1; i++) {
            if (v[i] != v[i - 1] + 1) {
                missing[k++] = v[i - 1] + 1;
            }

            if (v[i] == v[i - 1]) {
                dupno = v[i];
            }

            good &= k <= 2;
            cout << "B " << good << " ";
        }
        cout << endl;

        ll sum = accumulate(missing.begin(), missing.end(), 0LL);
        if (outlier != -1) {
            good &= sum == outlier;
            cout << "C " << good << endl;
        } else {
            good &= sum == dupno;
            cout << "D " << good << endl;
        }

        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
