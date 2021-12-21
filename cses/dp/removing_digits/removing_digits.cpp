#include <bits/stdc++.h>

using namespace std;

int memo[1000000 + 10];

int dp(int val) {
    if (val == 0) return 0;
    int &ans = memo[val];
    if (ans != -1) return ans;
    ans = INT_MAX;
    int cp = val;
    while (val > 0) {
        ans = min(ans, dp(cp - (val % 10)));
        val /= 10;
    }
    return ++ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}
