/*
 * Author: medbar
 * Date: 2021-09-16
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

typedef vector<int> vi;

vector<int> coins(100 + 10, 0);
int M = 1000000000 + 7;

//int memo[1000000 + 10];
int memo[100 + 10][1000000 + 10];

int n;

/*
int ways(int t, int value) {
    if (value < 0) return 0;
    if (value == 0) return 1;
    if (memo[value] != -1) return memo[value];
    int ret = 0;
    for (int i = t; i < n; i++) {
        ret = (ret + ways(i, value - coins[i])) % M;
    }
    return memo[value] = ret;
}
*/

/*
int ways(int type, int value) {
    for (int i = 0; i < coins.size(); i++) {
        memo[i][0] = 1;
    }

    int sum = 0;
    for (int t = 1; t <= n; t++) {
        for (int v = 1; v <= value; v++) {
            memo[t][v] = memo[t - 1][v];
            if (v - coins[t - 1] >= 0) memo[t][v - coins[t - 1]];
            if (memo[t][v] > M) memo[t][v] -= M;
        }
    }
    return memo[type][value];
}
*/

int ways(int type, int value) {
    if (value == 0) return 1;
    if ((value < 0) || (type == n)) return 0;

    int &ans = memo[type][value];
    if (ans != -1) return ans;

    ans = ways(type + 1, value) + ways(type, value - coins[type]);

    if (ans > M) {
        ans -= M;
    }
    return ans;
}

/*
   int ways(int n, int t, int s) {
   if (s < 0) return 0;
   if (s == 0 || t == n) return 1;
   if (memo[s] != -1) return memo[s];
   int ret = 0;
   for (int i = t; i < n; i++) {
   ret = (ret + ways(n, i, s - coins[i])) % M;
   }
   return memo[s] = ret;
   }
   */

int main() {
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    memset(memo, -1, sizeof memo);
    //sort(coins.begin(), coins.begin() + n, greater<int>());
    cout << ways(0, s) << endl;
    return 0;
}

