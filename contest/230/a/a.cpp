#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, n; cin >> s >> n;
    using ii = pair<int, int>;
    vector<ii> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const ii &a, const ii &b) -> bool {
            return a.first < b.first || (a.first == b.first && b.second > a.second);
            });

    bool good = true;
    for (auto i : v) {
        good &= s > i.first;
        s += i.second;
    }

    cout << (good ? "YES " : "NO") << endl;

    return 0;
}

