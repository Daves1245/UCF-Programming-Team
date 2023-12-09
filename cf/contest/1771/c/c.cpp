#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<bool> isprime(1e5, 1);
    vector<int> primes;
    isprime[0] = isprime[1] = 0;
    for (int i = 0; i < isprime.size(); i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < isprime.size(); j += i) {
                isprime[j] = false;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> v(n); for (int&i : v) cin >> i;
        unordered_map<int, bool> m;
        int f = 0;
        for (int i : v) {
            for (int d : primes) {
                if (d * d > i) break;
                if (!(i % d)) {
                    if (m[d]) {
                        f = 1;
                    }
                    m[d] = 1;
                }

                while (!(i % d)) {
                    i /= d;
                }
            }
            if (i != 1) {
                if (m[i]) f = 1;
                m[i] = 1;
            }
        }

        cout << (f ? "YES" : "NO") << endl;
    }

    return 0;
}
