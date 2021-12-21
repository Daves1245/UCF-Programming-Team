#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s.size() % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2, s.size());
        // cout << a << " " << b << endl;
        if (a != b) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}

