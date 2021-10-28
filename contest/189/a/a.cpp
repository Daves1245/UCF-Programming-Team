/*
 * Author: medbar
 * Date: 2021-10-27
 */

#include <cstring>
#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

ll memo[4010];

ll dp(ll sum, vi& choices, ll depth) {
	if (sum < 0) return 0;
	if (sum == 0) return depth;
    if (memo[sum] != -1) return memo[sum];

    ll ret = 0;
	for (int i = 0; i < (int) choices.size(); i++) {
        ll tmp = dp(sum - choices[i], choices, depth + 1);
        if (tmp > ret) {
            //cout << choices[i] << endl;
        }
        ret = max(ret, tmp);
	}

	return memo[sum] = ret;
}

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
    memset(memo, -1, sizeof memo);
	vi choices;
	choices.push_back(a);
	choices.push_back(b);
	choices.push_back(c);
    sort(choices.begin(), choices.end());
	cout << dp(n, choices, 0) << endl;
    return 0;
}

