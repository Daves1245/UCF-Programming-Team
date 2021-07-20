/*
 * Author: medbar
 * Date: 2021-07-10
 */

#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>

using namespace std;

struct custom_hash {
    // http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unordered_map<long long, int, custom_hash> safe_map;

int a[110];
int b[110];
int ans[220];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(a, 110, sizeof a);
        memset(b, 110, sizeof b);
        int k, n, m;
        scanf("%d %d %d", &k, &n, &m);
        vi ret;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        int ai = 0, bi = 0;
        int ansi = 0;
        int f = 0;
        while (ai + bi < n + m) {
            while ((ai < n) && (a[ai] == 0)) {
                ans[ansi] = a[ai];
                ansi++;
                //                printf("push 0 from a. k is %d, | ", k);
                k++;
                ai++;
                continue;
            }
            while ((bi < m) && (b[bi] == 0)) {
                ans[ansi] = b[bi];
                ansi++;
                //               printf("push 0 from b. k is %d, | ", k);
                k++;
                bi++;
                continue;
            }
            while ((ai < n) && (a[ai] != 0) && (a[ai] <= k)) {
                //              printf("push %d from a |  ", a[ai]);
                ans[ansi] = a[ai];
                ansi++;
                ai++;
                continue;
            }
            while ((bi < m) && (b[bi] != 0) && (b[bi] <= k)) {
                //             printf("push %d from b | ", b[bi]);
                ans[ansi] = b[bi];
                ansi++;
                bi++;
                continue;
            }
            printf("-1\n");
            f = 1;
            break;
        }
        if (f) {
            f = 0;
            continue;
        }
        for (int i = 0; i < ansi; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

