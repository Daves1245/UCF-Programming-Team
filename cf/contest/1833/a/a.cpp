#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string str; cin >> str;
        set<string> s;
        for (int i = 0; i < n - 1; i++) {
            if (s.count(str.substr(i, 2)) == 0) {
                s.insert(str.substr(i, 2));
            }
        }

        cout << s.size() << endl;
    }

    return 0;
}
