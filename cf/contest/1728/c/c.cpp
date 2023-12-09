#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push(x);
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.push(x);
        }

        int cnt = 0;
        while (a.size()) {
            if (a.top() == b.top()) {
                a.pop();
                b.pop();
                continue;
            }

            if (a.top() > b.top()) {
                int x = to_string(a.top()).size();
                a.pop();
                a.push(x);
                cnt++;
            } else {
                int x = to_string(b.top()).size();
                b.pop();
                b.push(x);
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
