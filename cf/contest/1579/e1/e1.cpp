#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto &i : v) cin >> i;
        deque<int> dq;
        dq.push_back(v[0]);
        for (int i = 1; i < n; i++) {
            if (v[i] < dq.front()) {
                dq.push_front(v[i]);
            } else {
                dq.push_back(v[i]);
            }
        }

        while (dq.size()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}
