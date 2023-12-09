#include <bits/stdc++.h>
using namespace std;
enum type {
    B = 2,
    X = 1,
    L = 0,
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        /*
type:
b_i: add to current set
l_i: remove corresponding b_i from set
x_j: print out max(x_j, max of set)
r_i: ignore (we can't teleport greater than this current pos with this int.)
*/
        // value, type, b_i (if type is L) or idx (if type is X)
        using st = tuple<int, int, int>;
        vector<st> v;
        vector<int> itb(n);
        for (int i = 0; i < n; i++) {
            int l, a, b, r; cin >> l >> r >> a >> b;
            v.push_back({l, L, i});
            v.push_back({b, B, i});
            itb[i] = b;
        }

        int q; cin >> q;
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            cin >> ans[i];
            v.push_back({ans[i], X, i});
        }

        sort(v.begin(), v.end(), greater<st>());
        multiset<int> s;

        vector<string> name = {"L", "X", "B"};

        // cout << "events:" << endl;
        // for (auto [val, type, i] : v) {
            // cout << val << " " << name[type] << " " << i << endl;
        // }

        for (auto [val, type, i] : v) {
            // cout << "event is " << val << " " << name[type] << " " << i << endl;
            switch (type) {
                case X:
                    ans[i] = val;
                    if (s.size()) {
                        ans[i] = max(val, *s.rbegin());
                        // cout << "multiset has max " << *s.rbegin() << endl;
                    }
                    // cout << "processing query ans[" << i << "] = " << ans[i] << endl;
                    break;
                case L:
                        // cout << "erased " << *s.rbegin() << " from multiset" << endl;
                        s.extract(*s.rbegin());
                    break;
                case B:
                    if (s.size()) {
                        // cout << "pushed " << *s.rbegin() << " to multiset" << endl;
                        s.insert(*s.rbegin());
                    } else {
                        // cout << "pushed " << val << " to multiset" << endl;
                        s.insert(val);
                    }
                    break;
            }

            // cout << "multi: ";
            // for (auto i : s) cout << i << " "; cout << endl;
        }

        for (auto i : ans) cout << i << " "; cout << endl;

    }
    return 0;
}
