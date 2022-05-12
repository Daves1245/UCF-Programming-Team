#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
    int N, W; cin >> N >> W;
    vi v(N + 1), w(N + 1);
    v[0] = w[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j + w[i] <= W)
                dp[j + w[i]] = max(dp[j], v[i] + dp[j]);
        }
    }

    for (auto i : dp) {
        cout << i << " ";
    }
    cout << endl;

    cout << dp[W] << endl;
    return 0;
}

