#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; string st; cin >> st;
        vector<int> s;

        for (int i = 0; i < n; i++) {
            while (s.size() && (st[i] > st[s.back()])) s.pop_back();
            s.push_back(i);
        }

        int m = s.size();
        for (int i = 0; i < m / 2; i++) swap(st[s[i]], st[s[m - 1 - i]]);

        int cnt = count(st.begin(), st.end(), st[s[m - 1]]);
        cout << (is_sorted(st.begin(), st.end()) ? m - cnt : -1) << endl;
    }

    return 0;
}
