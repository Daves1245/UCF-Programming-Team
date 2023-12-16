#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using big = __int128;
int main() {
    int t; cin >> t;

    auto sum = [](ll k, int len) -> big {
        big ret = 1;
        big bk = (big) k;
        for (int i = 0; i < len; i++) {
            if (ret > 1e27 / k) return 1e27;
            ret = ret * k;
        }
        return (ret - 1) / (bk - 1);
    };

    auto bs = [&](int len, big key) -> big {
        ll l = 2, r = 1e18, m;
        big ret;
        while (l <= r) {
            m = l + (r - l) / 2;
            big val = sum(m, len);
            if (key <= val) {
                ret = val;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ret;
    };

    while (t--) {
        ll n; cin >> n;

        big key = (big) n;
        
        int found = 0;
        for (int len = 3; len < 64; len++) {
            big check = bs(len, key);
            found |= check == key;
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
