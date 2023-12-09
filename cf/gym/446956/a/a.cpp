#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        set<string> se;
        for (int i = 0; i < s.size() - 1; i++) {
            se.insert(s.substr(i, 2));
        }

        cout << se.size() << endl;
    }

    return 0;
}
