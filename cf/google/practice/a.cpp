#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    // bitmask each row to set of bools, 1 if seat is reserved, 0 otherwise.
    vector<int> taken(5, 0);
    for (int i = 0; i < s.size(); i += 2) {
        int r = s[i] - 'A';
        int c = s[i + 1] - '0' - 1;
        taken[r] |= 1 << c;
    }

    int mcnt = 0;
    for (int i = 0; i < taken.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < 9; j++) {
            if (!((taken[i] >> j) & 1)) {
                cnt++;
            } else {
                cnt = 0;
            }
            mcnt = max(mcnt, cnt);
        }
    }
    return mcnt;
}

int main() {
    string s; cin >> s;
    cout << solution(s) << endl;
    return 0;
}
