#include <bits/stdc++.h>

using namespace std;

int M = 1000000000 + 7;
int n;

vector<int> coins(100 + 10);
long dp[1000001];

int main() {
    int s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s - coins[i]; j++) {
            dp[j + coins[i]] += dp[j];
            if (dp[j + coins[i]] > M) {
                dp[j + coins[i]] -= M;
            }
        }
    }

    cout << dp[s] << endl;
    return 0;
}
