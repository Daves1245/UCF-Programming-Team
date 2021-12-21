#include <bits/stdc++.h>

using namespace std;

int memo[1000000 + 10];
const int M = 1000000000 + 7;
vector<int> coins(100 + 10);
int n;

int ways(int value) {
    if (value == 0) return 1;
    if (value < 0) return 0;
    int &ans = memo[value];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + ways(value - coins[i])) % M;
    }
    return ans;
}

int main() {
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    memset(memo, -1, sizeof memo);
    cout << ways(s) << endl;
    return 0;
}

