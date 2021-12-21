#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 2021 + 10;
vector<vector<ll>> memo(N, vector<ll>(N, -1));
int m = 1000000000;

ll combo(int n, int k) {
    if (k == 0 || k == n) return 1;
    ll &ans = memo[n][k];
    if (ans != -1) return ans;
    return ans = (combo(n - 1, k - 1) + combo(n - 1, k)) % m;
}



int main() {
    int r, n;
    cin >> r >> n >> m;



    return 0;
}
