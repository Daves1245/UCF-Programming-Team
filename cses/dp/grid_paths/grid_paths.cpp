#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1010;

char grid[N][N];
int n;

int memo[N][N];

constexpr int M = 1000000000 + 7;

int ways(int i, int j) {
    if (i >= n || j >= n) {
        return 0;
    }

    int &ans = memo[i][j];

    if (grid[i][j] == '*') {
        return ans = 0;
    }

    if (ans != -1) {
        return ans;
    }


    return ans = (ways(i + 1, j) + ways(i, j + 1)) % M;
}

int iways(int n) {
    int dp[N][N];
    memset(dp, 0, sizeof dp);
    if (grid[0][0] != '*') {
        dp[0][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[0][i] = dp[0][i - 1];
        if (grid[i][0] == '*') {
            dp[i][0] = 0;
        }
        if (grid[0][i] == '*') {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    memset(memo, -1, sizeof memo);

    scanf("%d\n", &n);
    memo[n - 1][n - 1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = getchar();
        }
        getchar();
    }

    /*
    cout << ways(0, 0) << endl;
    */

    cout << iways(n) << endl;

    return 0;
}

