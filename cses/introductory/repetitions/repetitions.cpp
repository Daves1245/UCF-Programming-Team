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
    char c = s[0];
    int ma = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) count++;
        else c = s[i], count = 1;
        ma = max(ma, count);
    }
    cout << ma << endl;
    return 0;
}
