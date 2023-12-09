#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define read(a) for (auto &i : (a)) cin >> i
int main() {
    int n; cin >> n;
    vector<int> v;
    vector<int> a(n), b(n); read(a), v.push_back(i); read(b), v.push_back(i);
    sort(v.begin(), v.end());
    ll m = v[n];
    ll r = 0;
    bool good = *max_element(a.begin(), a.end()) <= *min_element(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        good &= a[i] <= b[i];
    }
    cout << (good ? r : -1) << endl;
    return 0;
}
