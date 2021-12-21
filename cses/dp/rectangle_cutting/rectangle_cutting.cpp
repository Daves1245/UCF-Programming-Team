#include <bits/stdc++.h>

using namespace std;

int memo[510][510];

int minmax(int a, int b) {
    if (a == b) return 0;
    int &ans = memo[a][b];
    if (ans != -1) return ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    int a, b;
    cin >> a >> b;

    cout << minmax(a, b) << endl;
    return 0;
}

