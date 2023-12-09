#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    set<char> un;
    unordered_map<int, char> m;
    int id = '9';
    string ret = "";
    for (char c : s) {
        if (un.count(c) == 0) {
            un.insert(c);
            m[c] = id;
            id--; // length at most 10 guarantees we never push an id below 0 to ret 
        }
        ret += m[c];
    }
    cout << ret << endl;
    return 0;
}
