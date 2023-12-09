#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        deque<int> dq;
        int oc = 0, ec = 0;
        // cout << "s " << s << endl;
        for (auto c : s) dq.push_back(c - '0'), (((c - '0') % 2) ? oc : ec)++;
        // cout << dq.size() << " " << (((dq.back() % 2) == 0) || (oc % 2)) << " " << oc % 2 << " " << (oc > 0) << endl;
        while (dq.size() && (((dq.back() % 2) == 0) || (oc % 2)) && (oc > 0)) {
            int d = dq.back();
            if (d % 2) oc--;
            else ec--;
            dq.pop_back();
        }

        if (!dq.size() || !oc) {
            cout << -1 << endl;
            continue;
        }
        while (dq.size()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}
