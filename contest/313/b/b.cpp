/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<int> v(s.size() + 10, 0);
    v[0] = s[0] == s[1];
    for (int i = 1; i <= s.size(); i++) {
        if (s[i] == s[i - 1]) v[i]++;
        v[i] += v[i - 1];
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cout << v[r - 1] - v[l - 1] << endl;
    }
    return 0;
}

