/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    int k = 0;
    v.erase(v.begin() + (v.size() + v[0].first - 1) % v.size());
    for (int i = 0; i < n - 2; i++) {
        int index = (v.size() + v[k].first - 1) % v.size();
        k++;
        if (k == v.size()) k--;
        cout << "caller: " << k << endl;
        for (auto i : v) {
            cout << "(" << i.first << ", " << i.second << ")";
        }
        cout << "index: " << index << endl;
        cout << endl;
        v.erase(v.begin() + index);
    }
    cout << v[0].second << endl;
    return 0;
}

