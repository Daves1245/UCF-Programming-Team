/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

#define lsb(x) ((x) & -(x))

using namespace std;

using vi = vector<int>;

class bit {
    public:
        vi ft;
        bit(int n) {
            ft.resize(n + 1);
            fill(ft.begin(), ft.end(), 0);
        }

        void flip(int i) {
            int v = query(i, i);
            for (; i <= ft.size(); i += lsb(i)) {
                if (v == 0) {
                    ft[i]++;
                } else {
                    ft[i]--;
                }
            }
        }

        int query(int i) {
            int ret = 0;
            for (; i; i -= lsb(i)) {
                ret += ft[i];
            }
            return ret;
        }

        int query(int i, int j) {
            return query(j) - query(i - 1);
        }
};

int main() {
    int n, k; cin >> n >> k;
    bit ft(n);
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        if (c == 'F') {
            int x; cin >> x;
            ft.flip(x);
        }
        if (c == 'C') {
            int l, r; cin >> l >> r;
            cout << ft.query(l, r) << endl;
        }
    }
    return 0;
}

