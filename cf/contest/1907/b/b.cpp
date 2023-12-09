#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        // vector<char> low, high;
        stack<int> low, high;
        int n = s.size();
        vector<int> show(n, 1);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'B') {
                show[i] = 0;
                if (high.size()) {
                    show[high.top()] = 0;
                    high.pop();
                }
            } else if (c == 'b') {
                if (low.size()) {
                    show[low.top()] = 0;
                    low.pop();
                }
                show[i] = 0;
            } else {
                if (isupper(c)) {
                    high.push(i);
                } else {
                    low.push(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (show[i]) cout << s[i];
        }
        cout << endl;
    }

    return 0;
}
