#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100000 + 10;
constexpr int M = 100 + 10;
constexpr int MOD = 1000000000 + 7;

int n, m;
vector<int> arr;
vector<vector<int>> dp(N, vector<int>(M + 1, 0));

int valid() {
    if (arr[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    }

    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        int v = arr[i];
        if (v == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= MOD;
                }
            }
        } else {
            for (int k : {v - 1, v, v + 1}) {
                if (k >= 1 && k <= m)
                    (dp[i][v] += dp[i - 1][k]) %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        (ans += dp[n - 1][i]) %= MOD;
    }
    return ans;
}

int main() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << valid() << endl;
    return 0;
}

