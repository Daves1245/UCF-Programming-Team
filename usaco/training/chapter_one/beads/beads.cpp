/*
 * Author: medbar
 * Date: 2021-09-12
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

ii pick_low(const char *beads, int i, int n, int color) {
    ii ret;
    int low_bound = i;
    while (low_bound > i - n && (beads[low_bound] == color || beads[low_bound] == 'w')) {
        low_bound--;
        ret.first++;
    }
    return ret;
}

int pick_high(const char *beads, int i, int n, int color, int bound) {
    int ret = 0;
    int high_bound = i;
    while (high_bound < bound + 2 * n && (beads[high_bound] == color || beads[high_bound] == 'w')) {
        high_bound++;
        ret++;
    }
    return ret;
}

int pick_beads(const char *beads, int i, int n) {
    ii red = pick_low(beads, i, n, 'r');
    ii blue = pick_low(beads, i, n, 'b');
    int ret = 0;
    if (pick_low(x))
    info.first += max(max(pick_high(beads, i, n, 'r', red.second), pick_high(beads, i, n, 'r', blue.second)), max(pick_high(beads, i, n, 'b', red.second), pick_high(beads, i, n, 'b', blue.second));
    return info.first;
}

int solve(const char *beads, int n) {
    int m = 0;
    for (int i = n; i <= 2 * n; i++) {
        m = max(m, pick_beads(beads, i, n));
    }
    return m;
}

int main() {
    int n;
    scanf("%d\n", &n);
    char input[n + 1], beads[3 * n + 1] = {0};
    fgets(input, sizeof input, stdin);
    strcpy(beads, input);
    strcpy(beads + strlen(beads), input);
    strcpy(beads + strlen(beads), input);
    printf("beads: %s\n", beads);
    printf("%d\n", solve(beads, n));
    return 0;
}

