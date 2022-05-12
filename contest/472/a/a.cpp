#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(1e6 + 10, true);

void init() {
    prime[1] = false;
    for (int i = 2; i < prime.size(); i++) 
        for (int j = i * i; j < prime.size(); j += i)
            prime[j] = false;
}

int main() {
    int n; cin >> n;
    init();
    for (int i = 4; i < n; i++) {
        if (!prime[i] && !prime[n - i]) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
    return 0;
}

