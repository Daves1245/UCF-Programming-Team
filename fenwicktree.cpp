#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define lso(x) ((x) & ~(x))

class bit {
    public:
        int n;
        vector<ll> v;
        bit(int n) {
            this->n = n;
            v.resize(n);
            fill(v.begin(), v.end(), 0);
        }

        void update(int i, int val) {
            while (i <= v.size()) {
                v[i] += val;
                i += lso(i);
            }
        }

        ll rsq(int i) {
            ll ret = 0;
            while (i > 0) {
                ret += lso(i);
                i -= lso(i);
            }
            return ret;
        }

        ll rsq(int i, int j) {
            return rsq(j) - rsq(i - 1);
        }
};
