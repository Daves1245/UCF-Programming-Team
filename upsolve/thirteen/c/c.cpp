/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

constexpr int N = 100;
constexpr int M = (int) 1e6;
constexpr int INF = (int) 1e9;

vi dp(2 * M + 10, INF);

// avg machine 8MB stack -> loose 10^6 bound on recursion
// (multiplicative in num local vars)
// RTE probably due to memory
int rec_dp(vi &coins, int val) {
    if (val < 0) return INF;
    if (val == 0) return 0;
    int &ret = dp[val];
    if (ret != 0) return ret;
    ret = INF;
    for (int i = 0; i < coins.size(); i++) {
        ret = min(ret, 1 + rec_dp(coins, val - coins[i]));
    }
    return ret;
}

bool iter_dp(vi &coins) {
    dp[0] = 0;
    dp[1] = 1;
    // building up greedily means taking the largest coin first, and only the largest coin
    // dp actually takes the minimum across all possible transitions (coin usages)
    for (int i = 0; i < 2 * M; i++) {
        for (int j = coins.size() - 1; j >= 0; j--) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INF && dp[i] == INF)
                dp[i] = dp[i - coins[j]] + 1;
        }
    }

    // bot brain moment
    for (int i = 1; i <= 2 * M; i++) {
        for (int j = coins.size() - 1; j >= 0; j--) {
            // the greedy is not optimal (we can add this coin to a solution for something
            // smaller and that ends up to have less coins than our greedy)
            // this is actually possible because a canonical coin system preserves
            // order (i.e. if x and y are sums we want the minimum coin change for and
            // M(x) = minimum number of coins required to produce x.
            // a proof can be found at this paper: https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf
            // as well as an O(n^2) algorithm in terms of input size to determine if the
            // system is canonical, but which I honestly don't comprehend at the moment.
            if (i - coins[j] >= 0 && dp[i] != INF && dp[i] > dp[i - coins[j]] + 1) {
                /*
                cout << "broke trying to produce sum of " << i << endl;
                cout << "coin is " << coins[j] << endl;
                cout << "dp[i] = " << dp[i] << " > dp[i - coins[j]] + 1 = " << dp[i - coins[j]] + 1 << endl;
                */
                return false;
            }
        }
    }

    return true;
}

int greedy(vi &v, long val) {
    int count = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        while (val >= v[i]) {
            val -= v[i];
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    // iter_dp(v);
    bool canon = iter_dp(v);
    /*
       for (int i = 0; i < n - 1; i++) {
       long long test = v[i] * ((long long) roundl((double) v[i + 1] / v[i]) + 0.1);
       if (greedy(v, test) != dp[test]) {
       canon = false;
       cout << "test is " << test << endl;
       cout << "broke at g = " << greedy(v, test) << " dp = " << dp[test];
       for (int i = 0; i <= test; i++) {
       cout << dp[i] << " ";
       }
       cout << endl;
       break;
       }
       }
       */

    cout << (canon ? "canonical" : "non-canonical") << endl;

    return 0;
}

