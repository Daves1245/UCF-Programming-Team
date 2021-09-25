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

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

//int memo[100 + 10][1000000 + 10];
int memo[1000000 + 10];
const int M = 1000000000 + 7;
vector<int> coins(100 + 10);
int N;
int min_coin = INT_MAX;

int ways(int value) {
    if (value == 0 || value == min_coin) return 1;
    if (value < min_coin) return 0;
    if (memo[value] != -1) return memo[value];
    //printf("ways called with value = %d\n", value);
    int ret = 0;
    for (int i = 0; i < N; i++) {
        /*
        printf("ways(%d)\n", value - coins[i]);
        printf("coins[i] = %d\n", coins[i]);
        */
        //printf("calling ways of %d\n", value - coins[i]);
        ret = (ret + ways(value - coins[i])) % M;
    }
    return memo[value] = ret;
}

int main() {
    int s;
    cin >> N >> s;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
        min_coin = min(min_coin, coins[i]);
    }
    memset(memo, -1, sizeof memo);
    cout << ways(s) << endl;
    return 0;
}

