#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1000 + 10;
constexpr int M = 100000 + 10;

int n, b;

vector<int> pages;
vector<int> cost;

/*
ll sack(int i, int b) {
    if (b <= 0 || i >= n) return 0;
    long &ans = dp[i][b];
    if (ans != -1) return ans;
    if (b - cost[i] < 0) return ans = sack(i + 1, b);
    return ans = max(pages[i] + sack(i + 1, b - cost[i]), sack(i + 1, b));
}
*/

ll isack(int b) {
    ll dp[M];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++) {
        for (int j = cost[i]; j <= b; j++) {
            dp[j - cost[i]] = max(dp[j - cost[i]], dp[j] + pages[i]);
        }
    }

    return dp[0];
}

int main() {

    cin >> n >> b;
    pages.resize(n);
    cost.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }


    // cout << sack(0, b) << endl;
    cout << isack(b) << endl;
    return 0;
}

