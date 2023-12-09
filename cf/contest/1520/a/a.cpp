#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        s.resize(unique(s.begin(), s.end()) - s.begin());
        set<char> se;
        for (auto c : s) se.insert(c);
        cout << (se.size() == s.size() ? "YES" : "NO") << endl;
    }
    return 0;
}
