#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        unordered_map<char, int> m;

        m['A'] = 1;
        m['B'] = 10;
        m['C'] = 100;
        m['D'] = 1000;
        m['E'] = 10000;

        char mc = s[n - 1];
        int res = 0;

        int ans = 0;

        vector<int> vals;
        int c = s[n - 1];
        for (int i = n - 1; i; i--) {
            int t = 0;
            mc = max(mc, s[i]);
            while (i && s[i] == c) {
                t++;
                i--;
            }

            if (mc > s[i]) {
                t *= -1 * m[s[i]];
            }
            vals.push_back(t);
        }

        for (auto i : vals) {
            cout << i << " ";
        }
        cout << endl;

        cout << accumulate(vals.begin(), vals.end(), 0LL) << endl;

        mc = s[n - 1];
        vector<int> freq(5, 0);
        for (int i = n - 1; i >= 0; i--) {
            freq[s[i] - 'A']++;
            mc = max(mc, s[i]);
            if (s[i] < mc) {
                res -= m[s[i]];
                if (accumulate(freq.begin() + s[i] - 'A', freq.end(), 0) <= 1) {
                    ans += 
                }
            }
            else {
                res += m[s[i]]; 
            }
        }

        cout << res << endl;
    }

    return 0;
}
