#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    vector<string> v;
    vector<int> a;
    int x = 0;
    for (int i = 1; i <= 9; i++) {
        string e = "";
        for (int j = 0; j < 4; j++) {
            e += to_string(i);
            v.push_back(e);
            a.push_back(x += e.size());
        }
    }
    while (t--) {
        string s; cin >> s;
        int i = find(v.begin(), v.end(), s) - v.begin();
        cout << a[i] << endl;
    }
    return 0;
}
