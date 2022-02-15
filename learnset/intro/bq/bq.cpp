#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        string gb;
        set<string> players;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            players.insert(s);
        }
        int tans = s;
        string nans;
        bool found = false;
        for (int i = 1; i <= s; i++) {
            string str;
            cin >> str;
            if (!found && players.count(str) > 0) {
                players.erase(players.find(str));
            }
            if (!found && players.size() == 1) {
                found = true;
                tans = i;
                nans = *players.begin();
            }
        }
        cout << nans << " " << tans << endl;
    }
    return 0;
}

