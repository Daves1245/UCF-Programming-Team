#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
int main() {
    vi a(4);
    for (auto &i : a) cin >> i;
    int ret = 0;
    string s; cin >> s;
    for (auto c : s) ret += a[c - '0' - 1];
    cout << ret << endl;
    return 0;
}
