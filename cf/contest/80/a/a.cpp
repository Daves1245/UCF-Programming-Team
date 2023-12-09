#include <bits/stdc++.h>
using namespace std;
int prime(int n) { if (n == 2) return true; if (!(n % 2)) return false;
for (int i = 3; i * i <= n; i += 2) if (!(n % i)) return false; return true; }
int main() {
    int a, b; cin >> a >> b;
    bool f = prime(a) && prime(b);
    for (int i = a + 1; i < b; i++) f &= !prime(i);
    cout << (f ? "YES" : "NO") << endl;
    return 0;
}
