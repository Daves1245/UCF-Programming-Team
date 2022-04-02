#include <bits/stdc++.h>

using namespace std;

struct target {
    int x, y, p;
};

int N = 1000;
int n;
vector<target> v;

using ld = long double;

ld distance(target &a, target b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    while (cin >> n && n != 0) {
        v.resize(n);
        for (int i = 0 ; i < n; i++) {
            cin >> v[i].x >> v[i].y >> v[i].p;
        }
        vector<ld> dp(n);
        target null = {0, 0, 0};
        dp[0] = distance(null, v[0]) + 1;
        dp[1] = min(distance(null, v[1]) + v[0].p, distance(null, v[0]) + 1 + distance(v[0], v[1]));
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + distance(v[i - 1], v[i]), dp[i - 2] + v[i - 1].p
                    + distance(v[i - 2], v[i]));
            dp[i]++;
        }

        cout << setprecision(3) << fixed << dp[n - 1] << endl;
    }
    return 0;
}

