#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<ll> a(n); for (auto &i : a) cin >> i;
        vector<ll> b(m); for (auto &i : b) cin >> i;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        auto amn = min_element(a.begin(), a.end());
        auto bmx = max_element(b.begin(), b.end());
        if (*amn < *bmx) {
            swap(*amn, *bmx);
        }
        if (!(k % 2)) {
            auto amx = max_element(a.begin(), a.end());
            auto bmn = min_element(b.begin(), b.end());
            if (*bmn < *amx) {
                swap(*bmn, *amx);
            }
        }

        ll s = accumulate(a.begin(), a.end(), 0LL);
        cout << s << endl;
    }
    return 0;
}
