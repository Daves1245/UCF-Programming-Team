#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < s.size(); i++) {
            (s[i] == 'a' ? a : b)[i]++;
        }

        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] - a[i] == b[j] - b[i]) {
                    start = i + 1, end = j;
                }
            }
        }

        cout << start << " " << end << endl;
    }

    return 0;
}
