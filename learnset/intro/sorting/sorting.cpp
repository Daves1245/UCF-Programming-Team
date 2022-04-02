#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end(), [](const string &a, const string &b) -> bool {
                int afreq[26] = {0};
                int bfreq[26] = {0};

                for (auto c : a) afreq[c - 'A']++;
                for (auto c : b) bfreq[c - 'A']++;

                int i = 0;
                while (i < 26 && afreq[i] == bfreq[i]) i++;
                return afreq[i] > bfreq[i];
                });

        cout << "Class #" << t << " ordering" << endl;
        for (auto i : v) cout << i << endl;
    }
    return 0;
}

