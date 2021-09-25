/*
 * Author: medbar
 * Date: 2021-09-20
 */

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

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);
        char word[n + 1];
        fgets(word, sizeof word, stdin);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] != '0') {
                ans += word[i] - '0';
                ans++;
            }
        }
        if (word[n - 1] != '0') ans--;
        printf("%d\n", ans);
    }
    return 0;
}

