#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n; cin >> n;
    ll a = 0;
    for (int i = 1; i <= n; i++) {
        a += (n % i);
    }
    cout << a << endl;
    return 0;
}
