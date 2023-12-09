#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> freq(26, 0);
        for (auto c : s) {
            freq[c - 'a']++;
        }

        int m = *max_element(freq.begin(), freq.end());
        set<char> u;
        string ret = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if ((freq[c - 'a'] >= m) && (u.count(c) == 0)) {
                ret += c;
                u.insert(c);
            }
        }
        reverse(ret.begin(), ret.end());
        cout << ret << endl;
    }

    return 0;
}
