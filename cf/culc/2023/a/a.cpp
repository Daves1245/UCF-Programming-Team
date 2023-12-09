#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n); for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    cout << accumulate(v.end() - k, v.end(), 0LL) + accumulate(v.begin(), v.end(), 0LL)  << endl;
    return 0;
}
