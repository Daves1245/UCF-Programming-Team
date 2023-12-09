#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    unordered_map<string, int> m;
    while (t--) {
        string s; cin >> s;
        m[s]++;
    }
    int ret = 0;
    string name;
    for (auto [k, v] : m) {
        if (v > ret) {
            ret = v;
            name = k;
        }
    }
    cout << name << endl;
    return 0;
}
